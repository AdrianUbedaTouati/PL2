
import java.util.Stack;
import java.util.TreeSet;

public class TraductorDR {

    private StringBuilder historialTraducion = new StringBuilder();
    private boolean flag = false;
    private Token token;
    private AnalizadorLexico lexico;
    private Stack<TablaSimbolos> padres = new Stack();
    private TablaSimbolos tablaSimbolos;

    public static final int
            Error_nombre_igual_funcion = 1,
            Error_sim_ya_existe = 2,
            Error_sim_no_declarado = 3,
            Error_num_entero = 4,
            Error_num_entero_o_real = 5,
            Error_num_no_entero_division_derecha = 6,
            Error_num_no_entero_division_izquierda = 7,
            Error_tabla_rango = 8;

    private class ParametroTipo {

        private ParametroTipo() {
            traduccion = "";
            tipo = 0;
        }
        private int tipo;

        private String traduccion;
    }

    public void comprobarFinFichero() {
        if (token.tipo == Token.EOF ) {
            if(flag) {
                System.out.println(historialTraducion);
            }
            System.exit(0);
        }
    }

    public TraductorDR(AnalizadorLexico al){
        flag = true;
        lexico = al;
        tablaSimbolos = new TablaSimbolos(null);
        padres.push(tablaSimbolos);

        token = lexico.siguienteToken();
        //S();
        //comprobarFinFichero();

    }

    public final void emparejar(int tokEsperado)
    {
        if (token.tipo == tokEsperado) {
            token = lexico.siguienteToken();
            //comprobarFinFichero();
        }
        else errorSintaxis(tokEsperado);
    }

    private void AnadirHistorialRegla(String tipoDeToken){
        //System.out.println("Tipo de token: "+tipoDeToken);
        historialTraducion.append(tipoDeToken);
        //comprobarFinFichero();
    }

    public final String S(){
        String traduccion = "";
        //System.out.println("token: " + token);
        if(token.tipo == Token.FUNCION){
            emparejar(Token.FUNCION);
            String id = token.lexema;

            emparejar(Token.ID); 

            emparejar(Token.PYC);

            String s = S();
            String b = B(id);
            traduccion = s+"\n"+"\n"+"float "+id+"()"+b;
        }else if(token.tipo == Token.EOF || token.tipo == Token.BLQ){}
        else errorSintaxis(Token.FUNCION,Token.EOF,Token.BLQ);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String D(String id){
        String traduccion = "";
        if(token.tipo == Token.VAR){

            emparejar(Token.VAR);
            String l = L(id);
            emparejar(Token.FVAR);
            traduccion = l;
        }else errorSintaxis(Token.VAR);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String L(String id){
        String traduccion = "";
        if(token.tipo == Token.ID){
            String v = V(id);
            String lp = Lp(id);
            traduccion = v + lp;
        } else errorSintaxis(Token.ID);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String Lp(String id){
        String traduccion = "";
        if(token.tipo == Token.ID){
            String v = V(id);
            String lp = Lp(id);
            traduccion = v + lp;
        }else if(token.tipo == Token.FVAR){

        } else errorSintaxis(Token.ID,Token.FVAR);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }



    public final String V(String nameFuncion){
        String traduccion = "";
        if(token.tipo == Token.ID){
            Token token_posible_error = token;
            String id = token.lexema;

            emparejar(Token.ID);
            emparejar(Token.DOSP);

            TablaSimbolos tabla = padres.pop();
            if (id.equals(nameFuncion)){
                errores_lexico(token_posible_error,Error_nombre_igual_funcion,null);
            }
            if (tabla.buscarAmbito(id) != null){
                errores_lexico(token_posible_error,Error_sim_ya_existe,null);
            }
            String idTrad = tabla.crearVariable(id);

            String c = C(idTrad).traduccion;

            String tipoDato = c.split(" ")[0].replace("*", "");
            int tipo = 0;
            if(tipoDato.equals("int")){
                tipo = Token.ENTERO;
            }else if(tipoDato.equals("float")){
                tipo = Token.REAL;
            }

            Simbolo sim = new Simbolo(id,tipo,idTrad);
            tabla.nuevoSimbolo(sim);

            padres.push(tabla);

            emparejar(Token.PYC);
            traduccion = c + ";"+"\n";
        }else errorSintaxis(Token.ID);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final ParametroTipo C(String name){
        ParametroTipo param = new ParametroTipo();
        if(token.tipo == Token.TABLA){
            String a = A();
            ParametroTipo c = C(name + a);
            param.tipo = Token.TABLA;
            param.traduccion = c.traduccion;
        }else if(token.tipo == Token.PUNTERO || token.tipo == Token.ENTERO || token.tipo == Token.REAL){
            String p = P();
            if(token.tipo == Token.PUNTERO){
                param.tipo = Token.PUNTERO;
            } else if(token.tipo == Token.ENTERO){
                param.tipo = Token.ENTERO;
            } else if (token.tipo == Token.REAL) {
                param.tipo = Token.REAL;
            }
            param.traduccion = p + " " + name;
        }
        else errorSintaxis(Token.TABLA,Token.PUNTERO,Token.ENTERO,Token.REAL);
        AnadirHistorialRegla(param.traduccion);
        return param;
    }

    public final String A(){
        String traduccion = "";
        if(token.tipo == Token.TABLA){
            emparejar(Token.TABLA);
            emparejar(Token.CORI);
            String r = R();
            emparejar(Token.CORD);
            emparejar(Token.DE);
            traduccion = r;
        } else errorSintaxis(Token.TABLA);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String R(){
        String traduccion = "";
        if(token.tipo == Token.NUMENTERO){
            String g = G();
            String rp = Rp();
            traduccion = g + rp;
        } else errorSintaxis(Token.NUMENTERO);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String Rp(){
        String traduccion = "";
        if(token.tipo == Token.COMA){
            emparejar(Token.COMA);
            String g = G();
            String rp = Rp();
            traduccion = g + rp;
        }else if(token.tipo == Token.CORD){

        } else errorSintaxis(Token.COMA,Token.CORD);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String G(){
        String traduccion = "";
        if(token.tipo == Token.NUMENTERO) {
            int num1,num2;
            num1 = Integer.parseInt(token.lexema);
            emparejar(Token.NUMENTERO);
            emparejar(Token.PTOPTO);
            if(token.tipo == Token.NUMENTERO) {
                num2 = Integer.parseInt(token.lexema);
            }else num2 = 0; //Va a dar error en el emparejar
            if(num2 < num1){
                errores_lexico(token,Error_tabla_rango,null);
            }
            emparejar(Token.NUMENTERO);
            traduccion = "["+(num2-num1+1)+"]";
        } else errorSintaxis(Token.NUMENTERO);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String P(){
        String traduccion = "";
        if(token.tipo == Token.PUNTERO){
            emparejar(Token.PUNTERO);
            emparejar(Token.DE);
            String p = P();
            traduccion =  p + "*";
        }else if(token.tipo == Token.ENTERO || token.tipo == Token.REAL){
            String tipo = Tipo();
            traduccion = tipo;
        } else errorSintaxis(Token.PUNTERO,Token.ENTERO,Token.REAL);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String Tipo(){
        String traduccion = "";
        if(token.tipo == Token.ENTERO){
            emparejar(Token.ENTERO);
            traduccion = "int";
        }else if(token.tipo == Token.REAL){
            emparejar(Token.REAL);
            traduccion = "float";
        } else errorSintaxis(Token.ENTERO,Token.REAL);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String B(String id){

        String traduccion = "";
        if(token.tipo == Token.BLQ){
            TablaSimbolos ultimoPadre = padres.pop();
            TablaSimbolos nuevoAmbito = new TablaSimbolos(ultimoPadre);
            padres.push(ultimoPadre);
            padres.push(nuevoAmbito);
            emparejar(Token.BLQ);
            String d = D(id);
            String si = SI(id);
            emparejar(Token.FBLQ);
            padres.pop();
            traduccion = "\n{\n" + d + si  + "\n}";
        } else errorSintaxis(Token.BLQ);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String SI(String id){
        String traduccion = "";
        if(token.tipo == Token.ID || token.tipo == Token.ESCRIBE || token.tipo == Token.BLQ){
            String i = I(id);
            String m = M(id);
            traduccion = i+m;
        } else errorSintaxis(Token.ID,Token.ESCRIBE,Token.BLQ);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String M(String id){
        String traduccion = "";
        if(token.tipo == Token.PYC){
            emparejar(Token.PYC);
            String i = I(id); //Se lo pongo para que la declaracion de I tenga sentido
            String m = M(id);
            traduccion = i+m;
        }else if(token.tipo == Token.FBLQ){

        } else errorSintaxis(Token.PYC,Token.FBLQ);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String I(String id){
        String traduccion = "";
        if(token.tipo == Token.ID){
            Token toke_posible_error = token;
            String nombre = token.lexema;
            emparejar(Token.ID);
            Token toke_posible_error_asignacion = token;
            emparejar(Token.ASIG);

            TablaSimbolos tabla = padres.pop();
            Simbolo sim = tabla.buscar(nombre);

            if(!id.equals(nombre)) {
                if (sim == null) {
                    errores_lexico(toke_posible_error, Error_sim_no_declarado, null);
                } else if (sim.tipo != Token.ENTERO && sim.tipo != Token.REAL) {
                    errores_lexico(toke_posible_error, Error_num_entero_o_real, tabla);
                }
            }

            padres.push(tabla);

            ParametroTipo e = E();

            if (id.equals(nombre)) {
                if(Token.REAL ==  e.tipo ) {
                    traduccion = "\n  return " + e.traduccion + ";";
                } else traduccion = "\n  return itor(" + e.traduccion + ");";
            }else{
                if(sim.tipo ==  e.tipo ) {
                    traduccion = "\n  "+sim.nomtrad + " = " + e.traduccion+";";
                }else if(sim.tipo ==  Token.REAL && e.tipo == Token.ENTERO){
                    traduccion = "\n  "+sim.nomtrad + " = " + "itor("+e.traduccion+")"+";";
                } else if(sim.tipo ==  Token.ENTERO && e.tipo == Token.REAL){
                    errores_lexico(toke_posible_error_asignacion,Error_num_entero,null);
                }
            }

        }else if(token.tipo == Token.ESCRIBE){
            emparejar(Token.ESCRIBE);
            emparejar(Token.PARI);
            ParametroTipo e = E();
            emparejar(Token.PARD);
            if(e.tipo == Token.REAL){
                traduccion = "\n  "+"printf("+"\"%f\","+e.traduccion+")"+";";
            }else{
                traduccion = "\n  "+"printf("+"\"%d\","+e.traduccion+")"+";";
            }
        } else if (token.tipo == Token.BLQ) {
            String b = B(id);  //Se lo pongo para que la declaracion de I tenga sentido
            traduccion = b;
        } else errorSintaxis(Token.ID,Token.ESCRIBE,Token.BLQ);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final ParametroTipo E(){
        ParametroTipo param = new ParametroTipo();
        if(token.tipo == Token.NUMENTERO || token.tipo == Token.NUMREAL || token.tipo == Token.ID){
            ParametroTipo t = T();
            param = Ep(t);
        } else errorSintaxis(Token.NUMENTERO,Token.NUMREAL,Token.ID);
        AnadirHistorialRegla(param.traduccion);
        return param;
    }

    public final ParametroTipo Ep(ParametroTipo parametro){
        ParametroTipo param = new ParametroTipo();
        if(token.tipo == Token.OPAS){
            String opas = token.lexema;
            emparejar(Token.OPAS);
            ParametroTipo t = T();
            if(parametro.tipo == Token.REAL && t.tipo == Token.REAL){
                param.traduccion = parametro.traduccion +" " + opas + "r " + t.traduccion;
                param.tipo  = Token.REAL;
            } else if (parametro.tipo == Token.REAL && t.tipo == Token.ENTERO) {
                param.traduccion = parametro.traduccion + " " +opas + "r " + "itor(" +t.traduccion +")";
                param.tipo  = Token.REAL;
            } else if (parametro.tipo == Token.ENTERO && t.tipo == Token.REAL) {
                param.traduccion = "itor(" + parametro.traduccion+ ") " + opas + "r " + t.traduccion;
                param.tipo  = Token.REAL;
            } else{
                param.traduccion = parametro.traduccion +" " + opas + "i " + t.traduccion;
                param.tipo  = Token.ENTERO;
            }
            param = Ep(param);
        }else if(token.tipo == Token.PYC || token.tipo == Token.FBLQ || token.tipo == Token.PARD){
            param = parametro;
        } else errorSintaxis(Token.OPAS,Token.PYC,Token.FBLQ,Token.PARD);
        AnadirHistorialRegla(param.traduccion);
        return param;
    }

    public final ParametroTipo T(){
        ParametroTipo param = new ParametroTipo();
        if(token.tipo == Token.NUMENTERO || token.tipo == Token.NUMREAL || token.tipo == Token.ID){
            ParametroTipo f = F();
            param = Tp(f);
        } else errorSintaxis(Token.NUMENTERO,Token.NUMREAL,Token.ID);
        AnadirHistorialRegla(param.traduccion);
        return param;
    }


    //ParametroTipo parametro
    public final ParametroTipo Tp(ParametroTipo parametro){
        ParametroTipo param = new ParametroTipo();
        if(token.tipo == Token.OPMUL){
            String opmul = token.lexema;
            Token toke_posible_error = token;
            emparejar(Token.OPMUL);

            ParametroTipo f = F();

            if (opmul.equals("//") || opmul.equals("%")){
                if (parametro.tipo == Token.REAL){
                    errores_lexico(toke_posible_error,Error_num_no_entero_division_izquierda,null);
                } else if (f.tipo == Token.REAL){
                    errores_lexico(toke_posible_error,Error_num_no_entero_division_derecha,null);
                }
            }

            if (parametro.tipo == Token.REAL && f.tipo == Token.REAL) {
                param.traduccion = parametro.traduccion +" " + opmul + "r " + f.traduccion;
                param.tipo = Token.REAL;
            }
            else if (parametro.tipo == Token.REAL && f.tipo == Token.ENTERO) {
                param.traduccion = parametro.traduccion + " " +opmul + "r " + "itor(" + f.traduccion + ")";
                param.tipo = Token.REAL;
            }
            else if (parametro.tipo == Token.ENTERO && f.tipo == Token.REAL) {
                    param.traduccion = "itor(" + parametro.traduccion + ")" +" " + opmul + "r " + f.traduccion;
                    param.tipo = Token.REAL;
            } else{
                if(opmul.equals("%")){
                    param.traduccion = parametro.traduccion+" " + opmul +" " + f.traduccion;
                    param.tipo = Token.ENTERO;
                }else if(opmul.equals("//")){
                    param.traduccion = parametro.traduccion +" " + "/i " + f.traduccion;
                    param.tipo = Token.ENTERO;
                }
                else if(opmul.equals("/"))
                {
                    param.traduccion = "itor("+parametro.traduccion+")" +" " + opmul + "r " +"itor("+ f.traduccion + ")";
                    param.tipo = Token.REAL;
                }
                else{
                    param.traduccion = parametro.traduccion +" " + opmul + "i " + f.traduccion;
                    param.tipo = Token.ENTERO;
                }
            }
            param = Tp(param);
        }else if(token.tipo == Token.OPAS || token.tipo == Token.PYC || token.tipo == Token.FBLQ || token.tipo == Token.PARD){
            param = parametro;
        }
        else errorSintaxis(Token.OPMUL,Token.OPAS,Token.PYC,Token.FBLQ,Token.PARD);
        AnadirHistorialRegla(param.traduccion);
        return param;
    }

    public final ParametroTipo F(){
        ParametroTipo param = new ParametroTipo();
        if(token.tipo == Token.NUMENTERO){
            String numentero = token.lexema;
            emparejar(Token.NUMENTERO);
            param.traduccion = numentero;
            param.tipo  = Token.ENTERO;
        }else if(token.tipo == Token.NUMREAL || token.tipo == Token.FBLQ || token.tipo == Token.PARD){
            String numreal = token.lexema;
            emparejar(Token.NUMREAL);
            param.traduccion = numreal;
            param.tipo  = Token.REAL;
        } else if (token.tipo == Token.ID) {
            String id = token.lexema;
            TablaSimbolos tabla = padres.pop();
            Simbolo simbolo = tabla.buscar(id);

            if (simbolo == null){
                errores_lexico(token,Error_sim_no_declarado,null);
            }else if(simbolo.tipo !=  Token.ENTERO && simbolo.tipo != Token.REAL) {
                errores_lexico(token,Error_num_entero_o_real,null);
            }

            emparejar(Token.ID);

            param.traduccion =  simbolo.nomtrad;
            param.tipo  = simbolo.tipo;
            padres.push(tabla);
        } else errorSintaxis(Token.NUMENTERO,Token.NUMREAL,Token.FBLQ,Token.PARD,Token.ID);
        AnadirHistorialRegla(param.traduccion);
        return param;
    }

    private void errorSintaxis(int... tiposDeTokens) {
        //System.out.println(historialTraducion);
        //System.exit(1);

        Token nombreToken = new Token();
        TreeSet<Integer> tokensEsperados = new TreeSet<>();

        StringBuilder FraseError;

        if (token.tipo == Token.EOF) {
            FraseError = new StringBuilder("Error sintactico: encontrado fin de fichero, esperaba");
        } else {
            FraseError = new StringBuilder("Error sintactico (" + token.columna + ',' + token.fila + "): encontrado '" + token.lexema + "', esperaba");
        }

        for (int tipoDeToken : tiposDeTokens) {
            tokensEsperados.add(tipoDeToken);
        }

        for (Integer elemento : tokensEsperados) {
            nombreToken.tipo = elemento;
            FraseError.append(" ").append(nombreToken.toString());
        }

        System.err.println(FraseError);

        System.exit(1);
    }

    private void errores_lexico(Token token, int err,TablaSimbolos tabla){

        if(err==Error_nombre_igual_funcion){
            System.err.println("Error semantico (" + token.columna +","+ token.fila +"): en '"+ token.lexema + "', no puede llamarse igual que la funcion");
        }
        else if(err==Error_sim_ya_existe){
            System.err.println("Error semantico (" + token.columna +","+ token.fila +"): en '"+ token.lexema + "', ya existe en este ambito");
        }
        else if(err==Error_sim_no_declarado){
            System.err.println("Error semantico (" + token.columna +","+ token.fila +"): en '"+ token.lexema + "', no ha sido declarado" );
        }
        else if(err==Error_num_entero){
            System.err.println("Error semantico (" + token.columna +","+ token.fila +"): en '"+ token.lexema + "', tipos incompatibles entero/real" );
        }
        else if(err==Error_num_entero_o_real){
            System.err.println("Error semantico (" + token.columna +","+ token.fila +"): en '"+ token.lexema + "',  debe ser de tipo entero o real");
        }
        else if(err==Error_num_no_entero_division_derecha){
            System.err.println("Error semantico (" + token.columna +","+ token.fila +"): en '"+ token.lexema + "', el operando derecho debe ser entero");
        }
        else if(err==Error_num_no_entero_division_izquierda){
            System.err.println("Error semantico (" + token.columna +","+ token.fila +"): en '"+ token.lexema + "', el operando izquierdo debe ser entero");
        }
        else if(err==Error_tabla_rango){
            System.err.println("Error semantico (" + token.columna +","+ token.fila +"): en '"+ token.lexema + "',  rango incorrecto");
        }
        System.exit(-1);
    }
}


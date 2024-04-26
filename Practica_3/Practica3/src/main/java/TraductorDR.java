
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
            NONE        = 0,
            ENTERO      = 1,
            REAL        = 2,
            FUNCION     = 3,
            BOOLEANO    = 4;

    private class ParametroTipo {

        private ParametroTipo() {
            traduccion = "";
            tipo = NONE;
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
        S();
        comprobarFinFichero();
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
        System.out.println("Tipo de token: "+tipoDeToken);
        historialTraducion.append(tipoDeToken);
        comprobarFinFichero();
    }


    public final String S(){
        String traduccion = "";
        //System.out.println("token: " + token);
        if(token.tipo == Token.FUNCION){
            emparejar(Token.FUNCION);
            String id = token.lexema;

            TablaSimbolos tabla = padres.pop();
            String idTrad = tabla.crearVariable(id);
            Simbolo sim = new Simbolo(id,Token.REAL,idTrad);
            tabla.nuevoSimbolo(sim);
            padres.push(tabla);


            emparejar(Token.ID); 

            emparejar(Token.PYC);

            String s = S();
            String b = B(token.lexema);
            traduccion = s+"float "+id+"()"+"\n   "+b;
        }else if(token.tipo == Token.EOF || token.tipo == Token.BLQ){}
        else errorSintaxis(Token.FUNCION,Token.EOF,Token.BLQ);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String D(){
        String traduccion = "";
        if(token.tipo == Token.VAR){

            emparejar(Token.VAR);
            String l = L();
            emparejar(Token.FVAR);
            traduccion = l;
        }else errorSintaxis(Token.VAR);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String L(){
        String traduccion = "";
        if(token.tipo == Token.ID){
            String v = V();
            String lp = Lp();
            traduccion = v + lp;
        } else errorSintaxis(Token.ID);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String Lp(){
        String traduccion = "";
        if(token.tipo == Token.ID){
            String v = V();
            String lp = Lp();
            traduccion = v + lp;
        }else if(token.tipo == Token.FVAR){

        } else errorSintaxis(Token.ID,Token.FVAR);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String V(){
        String traduccion = "";
        if(token.tipo == Token.ID){
            String id = token.lexema;

            emparejar(Token.ID);
            emparejar(Token.DOSP);
            String c = C(id);

            String tipoDato = c.split(" ")[0].replace("*", "");
            int tipo = 0;
            if(tipoDato.equals("int")){
                tipo = Token.ENTERO;
            }else if(tipoDato.equals("float")){
                tipo = Token.REAL;
            }
            TablaSimbolos tabla = padres.pop();

            String idTrad = tabla.crearVariable(id);
            Simbolo sim = new Simbolo(id,tipo,idTrad);
            tabla.nuevoSimbolo(sim);

            padres.push(tabla);

            emparejar(Token.PYC);
            traduccion = c + ";";
        }else errorSintaxis(Token.ID);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String C(String name){
        String traduccion = "";
        if(token.tipo == Token.TABLA){
            String a = A();
            String c = C(name);
            traduccion = c + a;
        }else if(token.tipo == Token.PUNTERO || token.tipo == Token.ENTERO || token.tipo == Token.REAL){
            String p = P();
            traduccion = p + " " + name;
        }
        else errorSintaxis(Token.TABLA,Token.PUNTERO,Token.ENTERO,Token.REAL);
        AnadirHistorialRegla(traduccion);
        return traduccion;
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
            String d = D();
            String si = SI(id);
            emparejar(Token.FBLQ);
            padres.pop();
            traduccion = "{" + d + si + "}";
        } else errorSintaxis(Token.BLQ);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String SI(String id){
        String traduccion = "";
        if(token.tipo == Token.ID || token.tipo == Token.ESCRIBE || token.tipo == Token.BLQ){
            String i = I(id);
            String m = M();
            traduccion = i+m;
        } else errorSintaxis(Token.ID,Token.ESCRIBE,Token.BLQ);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String M(){
        String traduccion = "";
        if(token.tipo == Token.PYC){
            emparejar(Token.PYC);
            String i = I(token.lexema); //Se lo pongo para que la declaracion de I tenga sentido
            String m = M();
            traduccion = ";"+i+m;
        }else if(token.tipo == Token.FBLQ){

        } else errorSintaxis(Token.PYC,Token.FBLQ);
        AnadirHistorialRegla(traduccion);
        return traduccion;
    }

    public final String I(String id){
        String traduccion = "";
        if(token.tipo == Token.ID){
            String nombre = token.lexema;
            emparejar(Token.ID);
            emparejar(Token.ASIG);
            ParametroTipo e = E();

            TablaSimbolos tabla = padres.pop();

            if(tabla.buscar(nombre) == null){
                errorSintaxis();
            }else if (id == token.lexema) { // igual a I.funcion ni puta idea
                traduccion = "return " + e.traduccion+";";
            }else traduccion = token.lexema + " = " + e.traduccion; // COSAS RARAS C.id ???

            padres.push(tabla);

        }else if(token.tipo == Token.ESCRIBE){
            emparejar(Token.ESCRIBE);
            emparejar(Token.PARI);
            ParametroTipo e = E();
            emparejar(Token.PARD);
            if(e.tipo == REAL){
                traduccion = "printf("+"\"%f\","+e.traduccion+")";
            }else{
                traduccion = "printf("+"\"%d\","+e.traduccion+")";
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
            param = Ep(t);
            if(parametro.tipo == REAL && param.tipo == REAL){
                param.traduccion = parametro.traduccion + opas + "r " + param.traduccion;
                param.tipo  = Token.REAL;
            } else if (parametro.tipo == REAL && param.tipo == ENTERO) {
                param.traduccion = parametro.traduccion + opas + "r " + "itor(" +param.traduccion +")";
                param.tipo  = Token.REAL;
            } else if (parametro.tipo == ENTERO && param.tipo == REAL) {
                param.traduccion = "itor(" + parametro.traduccion+ ")" + opas + "r " + param.traduccion;
                param.tipo  = Token.REAL;
            } else{
                param.traduccion = parametro.traduccion + opas + "i " + param.traduccion;
                param.tipo  = Token.ENTERO;
            }
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
            if(opmul.equals("//")){
                opmul = "/";
            }
            emparejar(Token.OPMUL);
            ParametroTipo f = F();
            param = Tp(f);
            if (param.tipo == REAL && parametro.tipo == REAL) {
                param.traduccion = parametro.traduccion + opmul + "r" + param.traduccion;
                param.tipo  = Token.REAL;
            }
            else if (param.tipo == REAL && parametro.tipo == ENTERO) {
                param.traduccion = parametro.traduccion+ opmul + "r" + "itor("+param.traduccion+")";
                param.tipo  = Token.REAL;
            }
            else if (param.tipo == ENTERO && parametro.tipo == REAL) {
                param.traduccion = "itor("+parametro.traduccion+ ")" + opmul + "r" + param.traduccion;
                param.tipo  = Token.REAL;
            } else{
                param.traduccion = parametro.traduccion + opmul + "i" + param.traduccion;
                param.tipo = Token.ENTERO;
            }
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
            String numentero = token.lexema;
            emparejar(Token.NUMREAL);
            param.traduccion = numentero;
            param.tipo  = Token.REAL;
        } else if (token.tipo == Token.ID) {
            String id = token.lexema;
            emparejar(Token.ID);
            param.traduccion = id;
            TablaSimbolos tabla = padres.pop();
            param.tipo  = tabla.buscar(id).tipo;
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
}


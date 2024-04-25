
import java.util.TreeSet;

public class TraductorDR {

    private StringBuilder historialTiposTokens = new StringBuilder();
    private boolean flag = false;
    private Token token;
    private AnalizadorLexico lexico;
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
                System.out.println(historialTiposTokens);
            }
            System.exit(0);
        }
    }

    public TraductorDR(AnalizadorLexico al){
        flag = true;
        lexico = al;
        tablaSimbolos = new TablaSimbolos(null);
    }


    public final void emparejar(int tokEsperado)
    {
        if (token.tipo == tokEsperado) {
            token = lexico.siguienteToken();
            //comprobarFinFichero();
        }
        else errorSintaxis(tokEsperado);
    }

    private void AnadirHistorialRegla(int tipoDeToken){
        historialTiposTokens.append(" "+ tipoDeToken);
        comprobarFinFichero();
    }


    public final String S(){
        String traduccion = "";
        if(token.tipo == Token.FUNCION){
            AnadirHistorialRegla(1);

            emparejar(Token.FUNCION);
            emparejar(Token.ID);
            emparejar(Token.PYC);

            String s = S();
            String b = B(token.lexema);
            return s+"float "+token.lexema+"()"+"\n   "+b;
        }else if(token.tipo == Token.EOF || token.tipo == Token.BLQ){
            AnadirHistorialRegla(2);
        }
        else errorSintaxis(Token.FUNCION,Token.EOF,Token.BLQ);
        return traduccion;
    }

    public final String D(){
        String traduccion = "";
        if(token.tipo == Token.VAR){
            AnadirHistorialRegla(3);
            String l = L();
            emparejar(Token.VAR);
            emparejar(Token.FVAR);
            return l;
        }else errorSintaxis(Token.VAR);
        return traduccion;
    }

    public final String L(){
        String traduccion = "";
        if(token.tipo == Token.ID){
            AnadirHistorialRegla(4);

            String v = V();
            String lp = Lp();
            return v + lp;
        } else errorSintaxis(Token.ID);
        return traduccion;
    }

    public final String Lp(){
        String traduccion = "";
        if(token.tipo == Token.ID){
            AnadirHistorialRegla(5);

            String v = V();
            String lp = Lp();
            return v + lp;
        }else if(token.tipo == Token.FVAR){
            AnadirHistorialRegla(6);
        } else errorSintaxis(Token.ID,Token.FVAR);
        return traduccion;
    }

    public final String V(){
        String traduccion = "";
        if(token.tipo == Token.ID){
            AnadirHistorialRegla(7);

            emparejar(Token.ID);
            emparejar(Token.DOSP);
            String c = C(token.lexema);
            emparejar(Token.PYC);
            return c + ";";
        }else errorSintaxis(Token.ID);
        return traduccion;
    }

    public final String C(String name){
        String traduccion = "";
        if(token.tipo == Token.TABLA){
            AnadirHistorialRegla(8);
            String a = A();
            String c = C(name);
            return c + a;
        }else if(token.tipo == Token.PUNTERO || token.tipo == Token.ENTERO || token.tipo == Token.REAL){
            AnadirHistorialRegla(9);
            String p = P();
            return p + " " + name;
        }
        else errorSintaxis(Token.TABLA,Token.PUNTERO,Token.ENTERO,Token.REAL);
        return traduccion;
    }

    public final String A(){
        String traduccion = "";
        if(token.tipo == Token.TABLA){
            AnadirHistorialRegla(10);

            emparejar(Token.TABLA);
            emparejar(Token.CORI);
            String r = R();
            emparejar(Token.CORD);
            emparejar(Token.DE);
            return r;
        } else errorSintaxis(Token.TABLA);
        return traduccion;
    }

    public final String R(){
        String traduccion = "";
        if(token.tipo == Token.NUMENTERO){
            AnadirHistorialRegla(11);

            String g = G();
            String rp = Rp();
            return g + rp;
        } else errorSintaxis(Token.NUMENTERO);
        return traduccion;
    }

    public final String Rp(){
        String traduccion = "";
        if(token.tipo == Token.COMA){
            AnadirHistorialRegla(12);

            emparejar(Token.COMA);
            String g = G();
            String rp = Rp();
            return g + rp;
        }else if(token.tipo == Token.CORD){
            AnadirHistorialRegla(13);
        } else errorSintaxis(Token.COMA,Token.CORD);
        return traduccion;
    }

    public final String G(){
        String traduccion = "";
        if(token.tipo == Token.NUMENTERO) {
            AnadirHistorialRegla(14);

            emparejar(Token.NUMENTERO);
            int num1 = Integer.parseInt(token.lexema);
            emparejar(Token.PTOPTO);
            emparejar(Token.NUMENTERO);
            int num2 = Integer.parseInt(token.lexema);
            return "["+(num2-num1+1)+"]";
        } else errorSintaxis(Token.NUMENTERO);
        return traduccion;
    }

    public final String P(){
        String traduccion = "";
        if(token.tipo == Token.PUNTERO){
            AnadirHistorialRegla(15);

            emparejar(Token.PUNTERO);
            emparejar(Token.DE);
            String p = P();
            return  p + "*";
        }else if(token.tipo == Token.ENTERO || token.tipo == Token.REAL){
            AnadirHistorialRegla(16);

            String tipo = Tipo();
            return tipo;
        } else errorSintaxis(Token.PUNTERO,Token.ENTERO,Token.REAL);
        return traduccion;
    }

    public final String Tipo(){
        String traduccion = "";
        if(token.tipo == Token.ENTERO){
            AnadirHistorialRegla(17);

            emparejar(Token.ENTERO);
            return "int";
        }else if(token.tipo == Token.REAL){
            AnadirHistorialRegla(18);

            emparejar(Token.REAL);
            return "float";
        } else errorSintaxis(Token.ENTERO,Token.REAL);
        return traduccion;
    }

    public final String B(String id){
        String traduccion = "";
        if(token.tipo == Token.BLQ){
            AnadirHistorialRegla(19);

            emparejar(Token.BLQ);
            String d = D();
            String si = SI(id);
            emparejar(Token.FBLQ);
            return "{" + d + si + "}";
        } else errorSintaxis(Token.BLQ);
        return traduccion;
    }

    public final String SI(String id){
        String traduccion = "";
        if(token.tipo == Token.ID || token.tipo == Token.ESCRIBE || token.tipo == Token.BLQ){
            AnadirHistorialRegla(20);

            String i = I(id);
            String m = M();
            return i+m;
        } else errorSintaxis(Token.ID,Token.ESCRIBE,Token.BLQ);
        return traduccion;
    }

    public final String M(){
        String traduccion = "";
        if(token.tipo == Token.PYC){
            AnadirHistorialRegla(21);

            emparejar(Token.PYC);
            String i = I(token.lexema); //Se lo pongo para que la declaracion de I tenga sentido
            String m = M();
            return ";"+i+m;
        }else if(token.tipo == Token.FBLQ){
            AnadirHistorialRegla(22);
        } else errorSintaxis(Token.PYC,Token.FBLQ);
        return traduccion;
    }

    public final String I(String id){
        String traduccion = "";
        if(token.tipo == Token.ID){
            AnadirHistorialRegla(23);

            emparejar(Token.ID);
            emparejar(Token.ASIG);
            ParametroTipo e = E();
            if(tablaSimbolos.buscar(id) == null){
                errorSintaxis();
            }else if (id == token.I) { // igual a I.funcion ni puta idea
                return "return " + e.traduccion+";";
            }else return token.lexema + " = " + e.traduccion; // COSAS RARAS C.id ???
        }else if(token.tipo == Token.ESCRIBE){
            AnadirHistorialRegla(24);

            emparejar(Token.ESCRIBE);
            emparejar(Token.PARI);
            ParametroTipo e = E();
            emparejar(Token.PARD);
            if(e.tipo == REAL){
                return "printf("+"%f"+")";
            }else{
                return "printf("+"%d"+")";
            }
        } else if (token.tipo == Token.BLQ) {
            AnadirHistorialRegla(25);

            String b = B(id);  //Se lo pongo para que la declaracion de I tenga sentido
            return b;
        } else errorSintaxis(Token.ID,Token.ESCRIBE,Token.BLQ);
        return traduccion;
    }

    public final ParametroTipo E(){
        ParametroTipo param = new ParametroTipo();
        if(token.tipo == Token.NUMENTERO || token.tipo == Token.NUMREAL || token.tipo == Token.ID){
            AnadirHistorialRegla(26);

            ParametroTipo t = T();
            ParametroTipo ep = Ep(t.tipo,t.traduccion);
            return ep;
        } else errorSintaxis(Token.NUMENTERO,Token.NUMREAL,Token.ID);
        return param;
    }

    public final ParametroTipo Ep(int tipo, String id){
        String traduccion = "";
        if(token.tipo == Token.OPAS){
            AnadirHistorialRegla(27);

            emparejar(Token.OPAS);
            T();
            Ep();
        }else if(token.tipo == Token.PYC || token.tipo == Token.FBLQ || token.tipo == Token.PARD){
            AnadirHistorialRegla(28);
        } else errorSintaxis(Token.OPAS,Token.PYC,Token.FBLQ,Token.PARD);
        return traduccion;
    }

    public final ParametroTipo T(){
        String traduccion = "";
        if(token.tipo == Token.NUMENTERO || token.tipo == Token.NUMREAL || token.tipo == Token.ID){
            AnadirHistorialRegla(29);

            F();
            Tp();
        } else errorSintaxis(Token.NUMENTERO,Token.NUMREAL,Token.ID);
        return traduccion;
    }

    public final String Tp(){
        String traduccion = "";
        if(token.tipo == Token.OPMUL){
            AnadirHistorialRegla(30);

            emparejar(Token.OPMUL);
            F();
            Tp();
        }else if(token.tipo == Token.OPAS || token.tipo == Token.PYC || token.tipo == Token.FBLQ || token.tipo == Token.PARD){
            AnadirHistorialRegla(31);
        } else errorSintaxis(Token.OPMUL,Token.OPAS,Token.PYC,Token.FBLQ,Token.PARD);
        return traduccion;
    }

    public final ParametroTipo F(){
        String traduccion = "";
        if(token.tipo == Token.NUMENTERO){
            AnadirHistorialRegla(32);

            emparejar(Token.NUMENTERO);
        }else if(token.tipo == Token.NUMREAL || token.tipo == Token.FBLQ || token.tipo == Token.PARD){
            AnadirHistorialRegla(33);

            emparejar(Token.NUMREAL);
        } else if (token.tipo == Token.ID) {
            AnadirHistorialRegla(34);

            emparejar(Token.ID);
        } else errorSintaxis(Token.NUMENTERO,Token.NUMREAL,Token.FBLQ,Token.PARD,Token.ID);
        return traduccion;
    }

    private void errorSintaxis(int... tiposDeTokens) {
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



import java.util.TreeSet;

public class AnalizadorSintacticoDR {

    private StringBuilder historialTiposTokens = new StringBuilder();
    private boolean flag = false;
    private Token token;
    private AnalizadorLexico lexico;


    public void comprobarFinFichero() {
        if (token.tipo == Token.EOF ) {
            if(flag) {
                System.out.println(historialTiposTokens);
            }
            System.exit(0);
        }
    }

    public AnalizadorSintacticoDR (AnalizadorLexico analizadorLexico){
        flag = true;
        lexico = analizadorLexico;
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

    private void AnadirHistorialRegla(int tipoDeToken){
        historialTiposTokens.append(" "+ tipoDeToken);
        comprobarFinFichero();
    }


    public final void S(){
        if(token.tipo == Token.FUNCION){
            AnadirHistorialRegla(1);

            emparejar(Token.FUNCION);
            emparejar(Token.ID);
            emparejar(Token.PYC);
            S();
            B();
        }else if(token.tipo == Token.EOF || token.tipo == Token.BLQ){
            AnadirHistorialRegla(2);
        }
        else errorSintaxis(Token.FUNCION,Token.EOF,Token.BLQ);
    }

    public final void D(){
        if(token.tipo == Token.VAR){
            AnadirHistorialRegla(3);

            emparejar(Token.VAR);
            L();
            emparejar(Token.FVAR);
        }else errorSintaxis(Token.VAR);
    }

    public final void L(){
        if(token.tipo == Token.ID){
            AnadirHistorialRegla(4);

            V();
            Lp();
        } else errorSintaxis(Token.ID);
    }

    public final void Lp(){
        if(token.tipo == Token.ID){
            AnadirHistorialRegla(5);

            V();
            Lp();
        }else if(token.tipo == Token.FVAR){
            AnadirHistorialRegla(6);
        } else errorSintaxis(Token.ID,Token.FVAR);
    }

    public final void V(){
        if(token.tipo == Token.ID){
            AnadirHistorialRegla(7);

            emparejar(Token.ID);
            emparejar(Token.DOSP);
            C();
            emparejar(Token.PYC);
        }else errorSintaxis(Token.ID);
    }

    public final void C(){
        if(token.tipo == Token.TABLA){
            AnadirHistorialRegla(8);

            A();
            C();
        }else if(token.tipo == Token.PUNTERO || token.tipo == Token.ENTERO || token.tipo == Token.REAL){
            AnadirHistorialRegla(9);

            P();
        }
        else errorSintaxis(Token.TABLA,Token.PUNTERO,Token.ENTERO,Token.REAL);
    }

    public final void A(){
        if(token.tipo == Token.TABLA){
            AnadirHistorialRegla(10);

            emparejar(Token.TABLA);
            emparejar(Token.CORI);
            R();
            emparejar(Token.CORD);
            emparejar(Token.DE);
        } else errorSintaxis(Token.TABLA);
    }

    public final void R(){
        if(token.tipo == Token.NUMENTERO){
            AnadirHistorialRegla(11);

            G();
            Rp();
        } else errorSintaxis(Token.NUMENTERO);
    }

    public final void Rp(){
        if(token.tipo == Token.COMA){
            AnadirHistorialRegla(12);

            emparejar(Token.COMA);
            G();
            Rp();
        }else if(token.tipo == Token.CORD){
            AnadirHistorialRegla(13);
        } else errorSintaxis(Token.COMA,Token.CORD);
    }

    public final void G(){
        if(token.tipo == Token.NUMENTERO) {
            AnadirHistorialRegla(14);

            emparejar(Token.NUMENTERO);
            emparejar(Token.PTOPTO);
            emparejar(Token.NUMENTERO);
        } else errorSintaxis(Token.NUMENTERO);
    }

    public final void P(){
        if(token.tipo == Token.PUNTERO){
            AnadirHistorialRegla(15);

            emparejar(Token.PUNTERO);
            emparejar(Token.DE);
            P();
        }else if(token.tipo == Token.ENTERO || token.tipo == Token.REAL){
            AnadirHistorialRegla(16);

            Tipo();
        } else errorSintaxis(Token.PUNTERO,Token.ENTERO,Token.REAL);
    }

    public final void Tipo(){
        if(token.tipo == Token.ENTERO){
            AnadirHistorialRegla(17);

            emparejar(Token.ENTERO);
        }else if(token.tipo == Token.REAL){
            AnadirHistorialRegla(18);

            emparejar(Token.REAL);
        } else errorSintaxis(Token.ENTERO,Token.REAL);
    }

    public final void B(){
        if(token.tipo == Token.BLQ){
            AnadirHistorialRegla(19);

            emparejar(Token.BLQ);
            D();
            SI();
            emparejar(Token.FBLQ);
        } else errorSintaxis(Token.BLQ);
    }

    public final void SI(){
        if(token.tipo == Token.ID || token.tipo == Token.ESCRIBE || token.tipo == Token.BLQ){
            AnadirHistorialRegla(20);

            I();
            M();
        } else errorSintaxis(Token.ID,Token.ESCRIBE,Token.BLQ);
    }

    public final void M(){
        if(token.tipo == Token.PYC){
            AnadirHistorialRegla(21);

            emparejar(Token.PYC);
            I();
            M();
        }else if(token.tipo == Token.FBLQ){
            AnadirHistorialRegla(22);
        } else errorSintaxis(Token.PYC,Token.FBLQ);
    }

    public final void I(){
        if(token.tipo == Token.ID){
            AnadirHistorialRegla(23);

            emparejar(Token.ID);
            emparejar(Token.ASIG);
            E();
        }else if(token.tipo == Token.ESCRIBE){
            AnadirHistorialRegla(24);

            emparejar(Token.ESCRIBE);
            emparejar(Token.PARI);
            E();
            emparejar(Token.PARD);
        } else if (token.tipo == Token.BLQ) {
            AnadirHistorialRegla(25);

            B();
        } else errorSintaxis(Token.ID,Token.ESCRIBE,Token.BLQ);
    }

    public final void E(){
        if(token.tipo == Token.NUMENTERO || token.tipo == Token.NUMREAL || token.tipo == Token.ID){
            AnadirHistorialRegla(26);

            T();
            Ep();
        } else errorSintaxis(Token.NUMENTERO,Token.NUMREAL,Token.ID);
    }

    public final void Ep(){
        if(token.tipo == Token.OPAS){
            AnadirHistorialRegla(27);

            emparejar(Token.OPAS);
            T();
            Ep();
        }else if(token.tipo == Token.PYC || token.tipo == Token.FBLQ || token.tipo == Token.PARD){
            AnadirHistorialRegla(28);
        } else errorSintaxis(Token.OPAS,Token.PYC,Token.FBLQ,Token.PARD);
    }

    public final void T(){
        if(token.tipo == Token.NUMENTERO || token.tipo == Token.NUMREAL || token.tipo == Token.ID){
            AnadirHistorialRegla(29);

            F();
            Tp();
        } else errorSintaxis(Token.NUMENTERO,Token.NUMREAL,Token.ID);
    }

    public final void Tp(){
        if(token.tipo == Token.OPMUL){
            AnadirHistorialRegla(30);

            emparejar(Token.OPMUL);
            F();
            Tp();
        }else if(token.tipo == Token.OPAS || token.tipo == Token.PYC || token.tipo == Token.FBLQ || token.tipo == Token.PARD){
            AnadirHistorialRegla(31);
        } else errorSintaxis(Token.OPMUL,Token.OPAS,Token.PYC,Token.FBLQ,Token.PARD);
    }

    public final void F(){
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



    /*
    //Excepciones
    public class ErrorSintactico extends Exception {
        private Token token;
        private String FraseError;
        private Token[] tokensEsperados;
        public ErrorSintactico(Token token,Token[] tokensEsperados) {
            this.token = token;
            this.tokensEsperados = tokensEsperados;
        }

        public void TokenInesperado(){
            FraseError = "Error sintactico (" + token.fila + ',' + token.columna + "): encontrado ’" + token.lexema + "’, esperaba";
            ImprimirTokensEsperados();
            System.exit(-1);
        }

        public void FinDeFicheroInesperado(){
            FraseError = "Error sintactico: encontrado fin de fichero, esperaba ";
            ImprimirTokensEsperados();
            System.exit(-1);
        }

        private void ImprimirTokensEsperados(){
            for(Token tokenActual: tokensEsperados){
                FraseError += ' ' + tokenActual.toString();
            }
        }
        */
}


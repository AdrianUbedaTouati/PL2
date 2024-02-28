
import java.io.RandomAccessFile;
public class AnalizadorSintacticoDR {

    private Token token;

    private AnalizadorLexico lexico;

    public AnalizadorSintacticoDR (AnalizadorLexico analizadorLexico){
        lexico = analizadorLexico;
    }

    public final void emparejar(int tokEsperado)
    {
        if (token.tipo == tokEsperado)
            token = lexico.siguienteToken();
        else
            errorSintaxis(tokEsperado);
    }


    public final void S(){
        if(token.tipo == Token.FUNCION){
            emparejar(Token.FUNCION);
            emparejar(Token.ID);
            emparejar(Token.PYC);
            S();
            B();
        }else if(token.tipo == Token.EOF || token.tipo == Token.BLQ){
            //System.exit(0);
        }
        else errorSintaxis(Token.FUNCION,Token.EOF,Token.BLQ);
    }

    public final void D(){
        if(token.tipo == Token.VAR){
            emparejar(Token.VAR);
            L();
            emparejar(Token.FVAR);
        }else errorSintaxis(Token.VAR);
    }

    public final void L(){
        if(token.tipo == Token.ID){
            V();
            Lp();
        } else errorSintaxis(Token.ID);
    }

    public final void Lp(){
        if(token.tipo == Token.ID){
            V();
            Lp();
        }else if(token.tipo == Token.FVAR){

        } else errorSintaxis(Token.ID,Token.FVAR);
    }

    public final void V(){
        if(token.tipo == Token.ID){
            emparejar(Token.ID);
            emparejar(Token.DOSP);
            C();
            emparejar(Token.PYC);
        }else errorSintaxis(Token.ID);
    }

    public final void C(){
        if(token.tipo == Token.TABLA){
            A();
            C();
        }else if(token.tipo == Token.PUNTERO || token.tipo == Token.ENTERO || token.tipo == Token.REAL){
            P();
        }
        else errorSintaxis(Token.TABLA,Token.PUNTERO,Token.ENTERO,Token.REAL);
    }

    public final void A(){
        if(token.tipo == Token.TABLA){
            emparejar(Token.TABLA);
            emparejar(Token.CORI);
            R();
            emparejar(Token.CORD);
            emparejar(Token.DE);
        } else errorSintaxis(Token.TABLA);
    }

    public final void R(){
        if(token.tipo == Token.NUMENTERO){
            G();
            Rp();
        } else errorSintaxis(Token.NUMENTERO);
    }

    public final void Rp(){
        if(token.tipo == Token.COMA){
            emparejar(Token.COMA);
            G();
            Rp();
        }else if(token.tipo == Token.CORD){

        } else errorSintaxis(Token.COMA,Token.CORD,Token.BLQ);
    }

    public final void G(){
        if(token.tipo == Token.NUMENTERO) {
            emparejar(Token.NUMENTERO);
            emparejar(Token.PTOPTO);
            emparejar(Token.NUMENTERO);
        } else errorSintaxis(Token.NUMENTERO);
    }

    public final void P(){
        if(token.tipo == Token.PUNTERO){
            emparejar(Token.PUNTERO);
            emparejar(Token.DE);
            P();
        }else if(token.tipo == Token.ENTERO || token.tipo == Token.REAL){
            Tipo();
        } else errorSintaxis(Token.PUNTERO,Token.ENTERO,Token.REAL);
    }

    public final void Tipo(){
        if(token.tipo == Token.ENTERO){
            emparejar(Token.ENTERO);
        }else if(token.tipo == Token.REAL){
            emparejar(Token.REAL);
        } else errorSintaxis(Token.ENTERO,Token.REAL);
    }

    public final void B(){
        if(token.tipo == Token.BLQ){
            emparejar(Token.BLQ);
            D();
            SI();
            emparejar(Token.FBLQ);
        } else errorSintaxis(Token.BLQ);
    }

    public final void SI(){
        if(token.tipo == Token.ID || token.tipo == Token.ESCRIBE || token.tipo == Token.BLQ){
            I();
            M();
        } else errorSintaxis(Token.ID,Token.ESCRIBE,Token.BLQ);
    }

    public final void M(){
        if(token.tipo == Token.PYC){
            emparejar(Token.PYC);
            I();
            M();
        }else if(token.tipo == Token.FBLQ){

        } else errorSintaxis(Token.PYC,Token.FBLQ);
    }

    public final void I(){
        if(token.tipo == Token.ID){
            emparejar(Token.ID);
            emparejar(Token.ASIG);
            E();
        }else if(token.tipo == Token.ESCRIBE){
            emparejar(Token.ESCRIBE);
            emparejar(Token.PARI);
            E();
            emparejar(Token.PARD);
        } else if (token.tipo == Token.BLQ) {
            B();
        } else errorSintaxis(Token.ID,Token.ESCRIBE,Token.BLQ);
    }

    public final void E(){
        if(token.tipo == Token.NUMENTERO || token.tipo == Token.NUMREAL || token.tipo == Token.ID){
            T();
            Ep();
        } else errorSintaxis(Token.NUMENTERO,Token.NUMREAL,Token.ID);
    }

    public final void Ep(){
        if(token.tipo == Token.OPAS){
            emparejar(Token.OPAS);
            T();
            Ep();
        }else if(token.tipo == Token.PYC || token.tipo == Token.FBLQ || token.tipo == Token.PARD){

        }
        else errorSintaxis(Token.OPAS,Token.PYC,Token.FBLQ,Token.PARD);
    }

    public final void T(){
        if(token.tipo == Token.NUMENTERO || token.tipo == Token.NUMREAL || token.tipo == Token.ID){
            F();
            Tp();
        }
        else errorSintaxis(Token.NUMENTERO,Token.NUMREAL,Token.ID);
    }

    public final void Tp(){
        if(token.tipo == Token.OPMUL){
            emparejar(Token.OPMUL);
            F();
            Tp();
        }else if(token.tipo == Token.OPAS || token.tipo == Token.PYC || token.tipo == Token.FBLQ || token.tipo == Token.PARD){

        }
        else errorSintaxis(Token.OPMUL,Token.OPAS,Token.PYC,Token.FBLQ,Token.PARD);
    }

    public final void F(){
        if(token.tipo == Token.NUMENTERO){
            emparejar(Token.NUMENTERO);
        }else if(token.tipo == Token.NUMREAL || token.tipo == Token.FBLQ || token.tipo == Token.PARD){
            emparejar(Token.NUMREAL);
        } else if (token.tipo == Token.ID) {
            emparejar(Token.ID);
        } else errorSintaxis(Token.OPAS,Token.PYC,Token.FBLQ,Token.PARD);
    }


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
    }
}

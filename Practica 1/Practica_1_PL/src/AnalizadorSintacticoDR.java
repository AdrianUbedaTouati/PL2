import java.io.RandomAccessFile;

public class AnalizadorSintacticoDR {

    public AnalizadorSintacticoDR (AnalizadorLexico aanalizadorLexico){

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

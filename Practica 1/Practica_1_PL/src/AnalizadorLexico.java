import java.io.IOException;
import java.io.RandomAccessFile;

public class AnalizadorLexico {
    private RandomAccessFile fichero;

    private int fila;

    private int columna;
    public AnalizadorLexico (RandomAccessFile fichero){
        this.fichero = fichero;

    }

    public String siguienteToken() throws IOException {
        StringBuilder tokenActual = new StringBuilder();
        while(true) {
            int byteRead = fichero.readByte();

            if (byteRead == -1) {
                break; //Fin de fichero
            }

            char asciiChar = (char) byteRead;
            tokenActual.append(asciiChar);

            if(esToken(tokenActual.toString())){
                break;
            }

            if(!posibleToken(tokenActual.toString())){
                try {
                    throw new ErrorLexico();
                } catch (ErrorLexico e){
                    e.CaracterIncorrecto(asciiChar);
                }
            }
        }
        return tokenActual.toString();
    }

    private boolean esToken(String posibleToken){
        for(String token : Token.nombreToken){
            if (token.equals(posibleToken)){
                return true;
            }
        }
        return false;
    }

    private boolean posibleToken(String posibleToken){
        int longitudToken = posibleToken.length();

        for (String token : Token.nombreToken) {
            if (token.length() >= longitudToken && token.startsWith(posibleToken)) {
                return true;
            }
        }
        return false;
    }

    //Excepciones
    public class ErrorLexico extends Exception {
        private String FraseError;

        public void CaracterIncorrecto(char caracterIncorrecto){
            FraseError = "Error lexico ("+ fila + ',' + columna + "): caracter ’" + caracterIncorrecto + "’ incorrecto";
            System.out.println(FraseError);
            System.exit(-1);
        }
        public void FinDeFicheroInesperado(){
            FraseError = "Error lexico: fin de fichero inesperado";
            System.out.println(FraseError);
            System.exit(-1);
        }
    }
}


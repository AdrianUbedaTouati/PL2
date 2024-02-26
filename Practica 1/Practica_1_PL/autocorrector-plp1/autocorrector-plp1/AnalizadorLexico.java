import java.io.IOException;
import java.io.RandomAccessFile;

public class AnalizadorLexico {
    private RandomAccessFile fichero;

    private int fila;

    private int columna;
    public AnalizadorLexico (RandomAccessFile fichero){
        this.fichero = fichero;
        while(true){
            System.out.println(siguienteToken());
        }
    }

    public String siguienteToken() {

        StringBuilder tokenActual = new StringBuilder();

        while(true) {
            try {
                int byteRead = fichero.readByte();

                if (byteRead == -1) {
                    try {
                        throw new ErrorLexico();
                    } catch (ErrorLexico e) {
                        e.FinDeFicheroInesperado();
                    }
                }

                //Camiar fila o columna
                if (byteRead == 9) {
                    columna++;
                    continue;
                } else {
                    fila++;
                }

                char asciiChar = (char) byteRead;
                tokenActual.append(asciiChar);

                if (esToken(tokenActual.toString())) {
                    break;
                }

                if (!posibleToken(tokenActual.toString())) {
                    try {
                        throw new ErrorLexico();
                    } catch (ErrorLexico e) {
                        e.CaracterIncorrecto(asciiChar);
                    }
                }
            }catch (IOException e){
                e.toString();
                System.exit(-1);
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


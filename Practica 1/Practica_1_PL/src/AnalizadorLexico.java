import java.io.IOException;
import java.io.RandomAccessFile;

public class AnalizadorLexico {
    private RandomAccessFile fichero;

    private int fila;

    private int columna;

    private int filaAnteDeColumnaNueva;

    private boolean tokenPersonalizable;

    private char CaracterActual;

    public AnalizadorLexico (RandomAccessFile fichero){
        this.fichero = fichero;
        while(true){
            System.out.println(siguienteToken());
        }
    }

    private boolean esCaracterOmitir(int byteRead){
        boolean omitirCaracter = false;

        //Camiar fila o columna
        if (byteRead == 9) {
            columna++;
            omitirCaracter = true;
        }
        //Salto de Linea o espacio o tabulador
        else if(byteRead == 32 || byteRead == 10){
            omitirCaracter = true;
        }
        else {
            fila++;
            omitirCaracter = false;
        }
        return omitirCaracter;
    }

    private boolean esTerminadoToken(String tokenActual, char asciiChar){
        boolean TokenCreado = false;
        if (esToken(tokenActual.toString())) {
            TokenCreado = true;
        }

        if (!posibleToken(tokenActual.toString())) {
            try {
                throw new ErrorLexico();
            } catch (ErrorLexico e) {
                e.CaracterIncorrecto(asciiChar);
            }
        }
        return TokenCreado;
    }

    public Token siguienteToken() {
        StringBuilder tokenActual = new StringBuilder();
        while(true) {
            try {
                int byteRead = fichero.readByte();

                //Fin de fichero inesperado
                if (byteRead == -1) {
                    try {
                        throw new ErrorLexico();
                    } catch (ErrorLexico e) {
                        e.FinDeFicheroInesperado();
                    }
                }

                if(esCaracterOmitir(byteRead)){
                    continue;
                }

                char asciiChar = (char) byteRead;
                tokenActual.append(asciiChar);

                if(esTerminadoToken(tokenActual.toString(),asciiChar)){
                    break;
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

            if(token.startsWith("'")){
                posibleToken = "'" + posibleToken + "'";
            }

            if (token.equals(posibleToken)){
                return true;
            }
        }
        return false;
    }

    private boolean posibleToken(String posibleToken){
        int longitudToken = posibleToken.length();

        for (String token : Token.nombreToken) {
            if (token.length() >= longitudToken) {
                if(token.startsWith("'")){
                    posibleToken = "'" + posibleToken;
                }
                if(token.startsWith(posibleToken)){
                    return true;
                }
            }
        }
        return false;
    }

    private char SiguienteCarater(){
        try {
            if(caracterActual == '\t'){
                columna ++;
                filaAnteDeColumnaNueva = fila;
                fila = 1;
            }
            return (char) fichero.readByte();
        } catch (IOException e){
            e.toString();
            System.exit(-1);
        }
        return 0;
    }

    private void Retroceder(){
        try {
            if(caracterActual == '\t'){
                columna --;
                fila = filaAnteDeColumnaNueva;
            }
            fichero.seek(fichero.getFilePointer() - 1);
        } catch (IOException e){
            e.toString();
            System.exit(-1);
        }
    }

    private Token Clasificacion(){
        int tipoToken = -1;
        String lexema;
        CaracterActual = SiguienteCarater();
        Token tokenActual = new Token();

        switch (CaracterActual) {
            case '(':
                tipoToken = 1;
                lexema = "(";
            case ')':
                tipoToken = 2;
                lexema = ")";
            case ',':
                tipoToken = 3;
                lexema = ",";
            case ':':
                CaracterActual = SiguienteCarater();
                if (CaracterActual == '=') {
                    tipoToken = 7;
                    lexema = ":=";
                }
                else {
                    Retroceder();
                    tipoToken = 4;
                    lexema = ":";
                }
            case '[':
                tipoToken = 5;
                lexema = "[";
            case ']':
                tipoToken = 6;
                lexema = "]";
            case ';':
                tipoToken = 8;
                lexema = ";";
            case '.':
                CaracterActual = SiguienteCarater();
                if (CaracterActual == '.') {
                    tipoToken = 9;
                    lexema = "..";
                }
                else {
                    Retroceder();
                    try {
                        throw new ErrorLexico();
                    } catch (ErrorLexico e) {
                        e.CaracterIncorrecto(CaracterActual);
                    }
                }
            case '+':
                tipoToken = 10;
                lexema = "+";
            case '-':
                tipoToken = 10;
                lexema = "-";
            case '*':
                tipoToken = 11;
                lexema = "*";
            case '/':
                CaracterActual = SiguienteCarater();
                if (CaracterActual == '/') {
                    tipoToken = 11;
                    lexema = "//";
                }
                else{
                    Retroceder();
                    tipoToken = 11;
                    lexema = "/";
                }
            case '%':
                tipoToken = 11;
                lexema = "%";
            default:
                if(Character.isDigit(CaracterActual)){
                    while(true){
                        CaracterActual = SiguienteCarater();

                    }
                } else if(Character.isLetter(CaracterActual)){

                } else if(CaracterActual == '\t'){

                }
            }
        return tokenActual;
    }

    private boolean esNumero

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


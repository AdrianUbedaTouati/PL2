import java.io.EOFException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class AnalizadorLexico {
    private final RandomAccessFile fichero;

    private int fila;

    private int columna;

    private int filaAnteDeColumnaNueva;

    private char caracterActual;

    private boolean finalizacionDeFicheroInesperada = false;

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

    private char SiguienteCaracter(){
        try {
            if(caracterActual == '\t'){
                columna ++;
                filaAnteDeColumnaNueva = fila;
                fila = 1;
            }
            return (char) fichero.readByte();
        } catch (EOFException e){
            if(finalizacionDeFicheroInesperada) {
                try {
                    throw new ErrorLexico();
                } catch (ErrorLexico error) {
                    error.FinDeFicheroInesperado();
                }
            }
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
        StringBuilder lexema = new StringBuilder();
        caracterActual = SiguienteCaracter();
        Token tokenActual = new Token();

        switch (caracterActual) {
            case '(':
                tipoToken = Token.PARI;
                lexema.append('(');
                break;
            case ')':
                tipoToken = Token.PARD;
                lexema.append(')');
                break;
            case ',':
                tipoToken = Token.COMA;
                lexema.append(',');
                break;
            case ':':
                lexema.append(':');
                caracterActual = SiguienteCaracter();
                if (caracterActual == '=') {
                    tipoToken = Token.ASIG;
                    lexema.append('=');
                }
                else {
                    Retroceder();
                    tipoToken = Token.DOSP;
                }
                break;
            case '[':
                tipoToken = Token.CORI;
                lexema.append('[');
                break;
            case ']':
                tipoToken = Token.CORD;
                lexema.append(']');
                break;
            case ';':
                tipoToken = Token.PYC;
                lexema.append(';');
            case '.':
                finalizacionDeFicheroInesperada = true;
                caracterActual = SiguienteCaracter();
                if (caracterActual == '.') {
                    tipoToken = Token.PTOPTO;
                    lexema.append("..");
                    finalizacionDeFicheroInesperada = false;
                }
                else {
                    Retroceder();
                    ExcepcionCaracterIncorrecto(caracterActual);
                }
                break;
            case '+':
                tipoToken = Token.OPAS;
                lexema.append('+');
                break;
            case '-':
                tipoToken = Token.OPAS;
                lexema.append('-');
                break;
            case '*':
                tipoToken = Token.OPMUL;
                lexema.append('*');
                break;
            case '/':
                lexema.append('/');
                caracterActual = SiguienteCaracter();
                if (caracterActual == '/') {
                    tipoToken = Token.OPMUL;
                    lexema.append("//");
                } else if (caracterActual == '*') {
                    OmitirTextoComentario();
                } else{
                    Retroceder();
                    tipoToken = Token.OPMUL;
                }
                break;
            case '%':
                tipoToken = Token.OPMUL;
                lexema.append('%');
                break;
            default:
                if(Character.isDigit(caracterActual)){
                    lexema.append(caracterActual);
                    return FiltracionNumero(tokenActual,lexema);
                } else if(Character.isLetter(caracterActual)){
                    lexema.append(caracterActual);
                    return FiltracionLetras(tokenActual,lexema);
                } else if(caracterActual == '\t'){

                }
        }
        return tokenActual;
    }

    private void OmitirTextoComentario(){
        while(true){
            caracterActual = SiguienteCaracter();
            if(caracterActual == '*'){
                caracterActual = SiguienteCaracter();
                if(caracterActual == '/'){
                    break;
                }
            }
        }
    }

    private Token FiltracionLetras(Token tokenActual,StringBuilder lexema) {
        while (true) {
            caracterActual = SiguienteCaracter();
            if (!Character.isLetter(caracterActual) && !Character.isDigit(caracterActual)) {
                Retroceder();
                switch (lexema.toString()) {
                    case ("funcion"):
                        tokenActual.tipo = Token.FUNCION;
                        break;
                    case ("var"):
                        tokenActual.tipo = Token.VAR;
                        break;
                    case ("fvar"):
                        tokenActual.tipo = Token.FVAR;
                        break;
                    case ("entero"):
                        tokenActual.tipo = Token.ENTERO;
                        break;
                    case ("real"):
                        tokenActual.tipo = Token.REAL;
                        break;
                    case ("tabla"):
                        tokenActual.tipo = Token.TABLA;
                        break;
                    case ("de"):
                        tokenActual.tipo = Token.DE;
                        break;
                    case ("puntero"):
                        tokenActual.tipo = Token.PUNTERO;
                        break;
                    case ("blq"):
                        tokenActual.tipo = Token.BLQ;
                        break;
                    case ("fblq"):
                        tokenActual.tipo = Token.FBLQ;
                        break;
                    case ("escribe"):
                        tokenActual.tipo = Token.ESCRIBE;
                        break;
                    default:
                        tokenActual.tipo = Token.ID;
                }
                tokenActual.lexema = lexema.toString();
                break;
            } else {
                lexema.append(caracterActual);
            }
        }
        return tokenActual;
    }
    private Token FiltracionNumero(Token tokenActual,StringBuilder lexema){
        boolean separadorAparecido = false;
        tokenActual.tipo = Token.NUMENTERO;
        while(true){
            caracterActual = SiguienteCaracter();
            if (Character.isDigit(caracterActual)) {
                lexema.append(caracterActual);
            } else if (!separadorAparecido && (caracterActual == '.' || caracterActual == '\\')) {
                separadorAparecido = true;
                lexema.append(caracterActual);
                caracterActual = SiguienteCaracter();
                if(!Character.isDigit(caracterActual)){
                    ExcepcionCaracterIncorrecto(caracterActual);
                }else{
                    lexema.append(caracterActual);
                }
                tokenActual.tipo = Token.NUMREAL;
            } else {
                Retroceder();
                break;
            }
        }
        tokenActual.lexema = lexema.toString();
        return tokenActual;
    }

    private void ExcepcionCaracterIncorrecto(char caracterIncorrecto){
        try {
            throw new ErrorLexico();
        } catch (ErrorLexico e) {
            e.CaracterIncorrecto(caracterIncorrecto);
        }
    }

    private void ExcepcionFinDeFicheroInesperado(){
        try {
            throw new ErrorLexico();
        } catch (ErrorLexico e) {
            e.FinDeFicheroInesperado();
        }
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


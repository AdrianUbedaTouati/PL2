import java.io.EOFException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class AnalizadorLexico {
    private final RandomAccessFile fichero;

    private int fila = 0;

    private int columna = 1;

    private int filaAnteDeColumnaNueva;

    private char caracterActual;

    private boolean finalizacionDeFicheroInesperada = false;

    private StringBuilder lexema;

    private int tipoToken;

    private boolean finDeFichero = false;

    public AnalizadorLexico (RandomAccessFile fichero){
        this.fichero = fichero;
        while(true){
            Token token = siguienteToken();
            System.out.print(token.lexema);
            System.out.print(" "+token.tipo+" ");
            System.out.println("("+token.columna+','+token.fila+')');
        }
    }

    /*
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
    */

    private char SiguienteCaracter(){
        char caracter = '@';
        try {
            if(caracterActual == '\n'){
                columna ++;
                filaAnteDeColumnaNueva = fila;
                fila = 1;
            }else{
                fila++;
            }
            caracter = (char) fichero.readByte();
        } catch (EOFException e){
            if(finalizacionDeFicheroInesperada) {
                try {
                    throw new ErrorLexico();
                } catch (ErrorLexico error) {
                    error.FinDeFicheroInesperado();
                }
            } else{
                finDeFichero = true;
            }
        } catch (IOException e){
            e.toString();
            System.exit(-1);
        }
        return caracter;
    }

    private void Retroceder(){
        try {
            if(caracterActual == '\n'){
                columna --;
                fila = filaAnteDeColumnaNueva;
            }else{
                fila--;
            }
            fichero.seek(fichero.getFilePointer() - 1);
        } catch (IOException e){
            e.toString();
            System.exit(-1);
        }
    }

    private Token siguienteToken(){
        boolean lexemaTipoInsertado = false;
        tipoToken = -1;
        lexema = new StringBuilder();
        PasarCaracteresOmitibles();

        if(finDeFichero){
            System.exit(0);
        }

        Token tokenActual = new Token();
        tokenActual.columna = columna;
        tokenActual.fila = fila;

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
                break;
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
                    tokenActual = FiltracionNumero(tokenActual,lexema);
                } else if(Character.isLetter(caracterActual)){
                    lexema.append(caracterActual);
                    tokenActual = FiltracionLetras(tokenActual,lexema);
                }
                lexemaTipoInsertado = true;
        }
        if(!lexemaTipoInsertado) {
            tokenActual.lexema = lexema.toString();
            tokenActual.tipo = tipoToken;
        }
        return tokenActual;
    }

    private void PasarCaracteresOmitibles(){
        while(true) {
            caracterActual = SiguienteCaracter();
            if (!CaracterOmitible()) {
                break;
            }
        }
    }

    private boolean CaracterOmitible(){
        boolean omitible = false;
        if(caracterActual == '@'){

        }
        if(caracterActual == ' ' || caracterActual == '\t' || caracterActual == '\n'){
            omitible = true;
        }
        return omitible;
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
                        tipoToken = Token.FUNCION;
                        break;
                    case ("var"):
                        tipoToken = Token.VAR;
                        break;
                    case ("fvar"):
                        tipoToken = Token.FVAR;
                        break;
                    case ("entero"):
                        tipoToken = Token.ENTERO;
                        break;
                    case ("real"):
                        tipoToken = Token.REAL;
                        break;
                    case ("tabla"):
                        tipoToken = Token.TABLA;
                        break;
                    case ("de"):
                        tipoToken = Token.DE;
                        break;
                    case ("puntero"):
                        tipoToken = Token.PUNTERO;
                        break;
                    case ("blq"):
                        tipoToken = Token.BLQ;
                        break;
                    case ("fblq"):
                        tipoToken = Token.FBLQ;
                        break;
                    case ("escribe"):
                        tipoToken = Token.ESCRIBE;
                        break;
                    default:
                        tipoToken = Token.ID;
                }
                tokenActual.tipo = tipoToken;
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
        char auxSeparador;
        tipoToken = Token.NUMENTERO;
        while(true){
            caracterActual = SiguienteCaracter();
            if (Character.isDigit(caracterActual)) {
                lexema.append(caracterActual);
            } else if (!separadorAparecido && (caracterActual == '.' || caracterActual == '\\')) {
                separadorAparecido = true;
                auxSeparador = caracterActual;
                caracterActual = SiguienteCaracter();
                if(caracterActual == '.'){
                    Retroceder();
                    Retroceder();
                    break;
                }
                else if(!Character.isDigit(caracterActual)){
                    ExcepcionCaracterIncorrecto(caracterActual);
                }else{
                    lexema.append(auxSeparador);
                    lexema.append(caracterActual);
                }
                tipoToken = Token.NUMREAL;
            } else {
                Retroceder();
                break;
            }
        }
        tokenActual.tipo = tipoToken;
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
            FraseError = "Error lexico ("+ columna + ',' + fila + "): caracter ’" + caracterIncorrecto + "’ incorrecto";
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


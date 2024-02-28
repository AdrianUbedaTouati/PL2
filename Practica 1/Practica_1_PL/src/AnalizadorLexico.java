import java.io.EOFException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class AnalizadorLexico {
    private final RandomAccessFile fichero;
    private int fila = 0;
    private int columna = 1;
    private char caracterActual;
    private boolean finalizacionDeFicheroInesperada = false;
    private StringBuilder lexema;
    private int tipoToken;
    private boolean finDeFichero = false;

    public AnalizadorLexico (RandomAccessFile fichero){
        this.fichero = fichero;
        /*
        while(true){
            Token token = siguienteToken();
            String frase = "Token: "+token.columna+","+token.fila+" "+token.lexema+"  -> ("+token.columna+","+token.fila+"): "+token.lexema+" es de tipo "+token.tipo;
            System.out.println(frase);
            System.out.println();
        }
        */
    }

    private char SiguienteCaracter(){
        char caracter = '@';
        try {
            if(caracterActual == '\n'){
                columna ++;
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
            fila--;
            fichero.seek(fichero.getFilePointer() - 1);
            fichero.seek(fichero.getFilePointer() - 1);
            caracterActual = (char) fichero.readByte();
        } catch (IOException e){
            e.toString();
            System.exit(-1);
        }
    }

    public Token siguienteToken(){
        boolean lexemaTipoInsertado = false;
        tipoToken = -1;
        lexema = new StringBuilder();
        PasarCaracteresOmitibles();

        Token tokenActual = new Token();
        tokenActual.columna = columna;
        tokenActual.fila = fila;

        if(finDeFichero){
            //System.exit(0);
            tokenActual.tipo = Token.EOF;
            return tokenActual;
        }

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
                caracterActual = SiguienteCaracter();
                if (caracterActual == '/') {
                    tipoToken = Token.OPMUL;
                    lexema.append("//");
                } else if (caracterActual == '*') {
                    OmitirTextoComentario();
                    return siguienteToken();
                } else{
                    lexema.append('/');
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
                }else{
                    ExcepcionCaracterIncorrecto(caracterActual);
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
                if(!Character.isDigit(caracterActual)){
                    Retroceder();
                    Retroceder();
                    break;
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


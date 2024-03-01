import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Objects;

public class AnalizadorLexico {
    private int filaFichero = 1;
    private int columnaFichero = 0;
    RandomAccessFile texto;
    AnalizadorLexico(RandomAccessFile entrada) {
        texto = entrada;
    }

    /**
     * Devuelve el siguiente token del fichero
     * @return Token
     */
    private boolean terminar = false;
    private boolean comentario = false;
    private long ultimoSaltoLinea;
    private int columnaAntigua;

    public Token siguienteToken(){
        Token token = new Token();
        token.lexema = "";
        String caracterString;

        do{
            caracterString = LecturaFichero();

            if(terminar){
                //System.err.println("Error lexico: fin de fichero inesperado");
                token.tipo = 21;
                token.columna = columnaFichero;
                token.fila = filaFichero;
                return token;
            }

            token.columna = columnaFichero;
            token.fila = filaFichero;

            switch (caracterString) {
                case "(":
                    caracterString = LecturaFichero();
                    if (Objects.equals(caracterString, "*")) {
                        comentario = true;
                        EsComentario(token);
                    } else {
                        token.lexema = "(";
                        token.tipo = 0;
                        RetrocederFichero();
                    }
                    break;

                case ")":
                    token.lexema = caracterString;
                    token.tipo = 1;

                    break;

                case "+":
                    token.lexema = caracterString;
                    token.tipo = 2;
                    break;
                case "-":
                    token.lexema = caracterString;
                    token.tipo = 2;
                    break;

                case ";":
                    token.lexema = caracterString;
                    token.tipo = 3;
                    break;

                case ":":
                    token.lexema = caracterString;
                    token.tipo = 4;
                    caracterString = LecturaFichero();
                    if (Objects.equals(caracterString, "=")) {
                        token.lexema += caracterString;
                        token.tipo = 5;
                    } else {
                        RetrocederFichero();
                    }
                    break;

                //Casos especiales
                case " ":
                    break;
                case "\t":
                    break;
                case "\r":
                    break;
                case "\n":
                    break;

                default:
                    if (IsANum(caracterString) || IsAlfa(caracterString)) {
                        RetrocederFichero();
                        token = LexemaExtensible(token);
                    } else {
                        System.err.println("Error lexico (" + filaFichero + "," + columnaFichero + "): caracter '" + caracterString + "' incorrecto");
                        System.exit(-1);
                    }
            }
        }while (Objects.equals(token.lexema, ""));

        return token;
    }

    /**
     * Es el metodo encargado de leer cada caracter del fichero,
     * si detecta el fin del fichero cierra el programa con System.exit(-1)
     * @return Caracter a leer
     */
    private String LecturaFichero(){
        String caracterString = new String();
        try{
            int caracterAscii = texto.read();
            caracterString = Character.toString((char) caracterAscii);
            //System.out.println(caracterAscii);
            //Fin del fichero
            if(caracterAscii == -1){
                terminar = true;
            }
            //System.out.println(caracterString);
            //System.out.println(caracterString);
            if(caracterAscii == 10 && ultimoSaltoLinea != texto.getFilePointer()){
                ultimoSaltoLinea = texto.getFilePointer();
                columnaAntigua = columnaFichero;
                columnaFichero = 0;
                filaFichero++;
            }else{
                columnaFichero++;
                //columnaAntigua = columnaFichero;
            }


        } catch (IOException e) {
            System.err.println("Error al leer el fichero" + e.getMessage());
        }
        return caracterString;
    }

    /**
     * Se encagar de enviar el puntero de la lectura del fichero uno mas atras,
     * cuando retrocede, columnaFichero disminuye en 1
     */
    private void RetrocederFichero(){
        try{
            texto.seek(texto.getFilePointer()-1);
            columnaFichero--;
        } catch (IOException e) {
            System.err.println("Error al leer el fichero" + e.getMessage());
        }
    }

    /**
     * Es el metodo encargado de crear los tokens variables
     * @param token
     * @return token
     */
    private Token LexemaExtensible(Token token){
        String caracterString = LecturaFichero();
        if(IsANum(caracterString)){
            token.tipo = 19;
            do{
                if(!Objects.equals(caracterString, ".")) {
                    token.lexema += caracterString;
                } else if(Objects.equals(caracterString, ".")){
                    caracterString = LecturaFichero();
                    RetrocederFichero();
                    if(!IsANum(caracterString)){
                        if(columnaFichero == -1){
                            columnaFichero = columnaAntigua;
                            filaFichero--;
                        }
                        break;
                    }else{
                        token.lexema += ".";
                        token.tipo = 20;
                    }
                }
                caracterString = LecturaFichero();
            }while(IsANum(caracterString) || Objects.equals(caracterString, "."));
            RetrocederFichero();
        } else if(IsAlfa(caracterString)){
            token.tipo = 18;
            //System.out.println("hola");
            do{
                //System.out.println(caracterString);
                token.lexema += caracterString;
                caracterString = LecturaFichero();
            }while(IsAlfa(caracterString) || IsANum(caracterString));
            RetrocederFichero();
        }
        IsComand(token);

        return token;
    }

    /**
     * Verifica si el caracter pasado como parametro es un numero
     * @param lexema
     * @return
     */
    public boolean IsANum(String lexema){
        return lexema != null && lexema.matches("[0-9]{1}");
    }

    /**
     * Verifica si el caracter pasado como parametro es una letra Minuscula o Mayuscula
     * @param lexema
     * @return
     */
    public boolean IsAlfa(String lexema){
        return lexema.matches("[a-zA-Z]{1}");
    }

    /**
     * Verifica que el token no es un comando, antes de llamar a este metodo los tokens seran
     * tratados como ID
     * @param token
     */
    private void IsComand(Token token){
        switch (token.lexema){
            case "var":
                token.tipo = 6;
                token.lexema = "var";
                break;
            case "real":
                token.tipo = 7;
                token.lexema = "real";
                break;
            case "entero":
                token.tipo = 8;
                token.lexema = "entero";
                break;
            case "algoritmo":
                token.tipo = 9;
                token.lexema = "algoritmo";
                break;
            case "blq":
                token.tipo = 10;
                token.lexema = "blq";
                break;
            case "fblq":
                token.tipo = 11;
                token.lexema = "fblq";
                break;
            case "si":
                token.tipo = 12;
                token.lexema = "si";
                break;
            case "entonces":
                token.tipo = 13;
                token.lexema = "entonces";
                break;
            case "fsi":
                token.tipo = 14;
                token.lexema = "fsi";
                break;
            case "mientras":
                token.tipo = 15;
                token.lexema = "mientras";
                break;
            case "hacer":
                token.tipo = 16;
                token.lexema = "hacer";
                break;
            case "escribir":
                token.tipo = 17;
                token.lexema = "escribir";
                break;
        }
    }

    private void EsComentario(Token token) {
        String caracterString;
        do {
            if (terminar) {
                token.tipo = 21;
                token.columna = columnaFichero;
                token.fila = filaFichero;
                System.err.println("Error lexico: fin de fichero inesperado");
                System.exit(-1);
            }

            caracterString = LecturaFichero();

            if (Objects.equals(caracterString, "*")) {
                caracterString = LecturaFichero();
                if (Objects.equals(caracterString, ")")) {
                    comentario = false;
                }else {
                    RetrocederFichero();
                }
            }
        } while (comentario);
    }
}



import java.io.RandomAccessFile;
import java.io.FileNotFoundException;
import java.io.IOException;

class plp1 {
    public static void main(String[] args) {
        String nombreFichero= "p01.txt";
        try {
            RandomAccessFile entrada = new RandomAccessFile(nombreFichero,"r");
            AnalizadorLexico al = new AnalizadorLexico(entrada);
            //AnalizadorSintacticoDR asdr = new AnalizadorSintacticoDR(al);

            //asdr.S(); // simbolo inicial de la gramatica
            //asdr.comprobarFinFichero();
        }
        catch (FileNotFoundException e) {
            System.out.println("Error, fichero no encontrado: " + args[0]);
        }
    }




}





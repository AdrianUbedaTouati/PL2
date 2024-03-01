
import java.util.Stack;
import java.util.TreeSet;

public class AnalizadorSintacticoSLR {

    private Token token;
    private AnalizadorLexico lexico;
    private boolean flag;

    private Stack cadena = new Stack();

    //38 estados con 18 tipos
    private Accion acciones[][] = new Accion[38][18];
    private int irA [][] = new int[38][11];
    private int parteDerecha [] = new int[19];

    private Stack pila = new Stack();

    AnalizadorSintacticoSLR(AnalizadorLexico al){
        flag = true;
        lexico = al;
        ParteDerechaTabla();
        CreacionTabla();
        irATabla();
    }

    private class Accion{
        private static final int ACEPTAR = 0, DESPLAZAMIENTO = 1, REDUCCION = 2;
        private int movimiento;
        private int dirrecion;

        private Accion(int Movimiento, int Dirrecion)
        {
            movimiento = Movimiento;
            dirrecion = Dirrecion;
        }
    }

        private int parteIzquierda(int i) {
            cadena.push(i);
            if (i == 1) {
                return S;
            } else if (i == 2) {
                return D;
            } else if (i == 3 || i == 4) {
                return L;
            } else if (i == 5) {
                return V;
            } else if (i == 6 || i ==7) {
                return TIPO;
            } else if (i == 8) {
                return B;
            } else if (i == 9 || i == 10) {
                return SI;
            } else if (i == 11 || i == 12 || i == 13) {
                return I;
            } else if (i == 14 || i == 15) {
                return E;
            } else if (i == 16 || i == 17 || i == 18){
                return F;
            } else{
                return -1; //error
            }
        }
        private static final int
                X = 0,
                S = 1,
                D = 2,
                L = 3,
                V = 4,
                TIPO = 5,
                B = 6,
                SI = 7,
                I = 8,
                E = 9,
                F = 10;

    private void ParteDerechaTabla(){
        parteDerecha[1] = 4;

        parteDerecha[2] = 3;
        parteDerecha[3] = 2;
        parteDerecha[4] = 1;
        parteDerecha[5] = 4;
        parteDerecha[6] = 1;

        parteDerecha[7] = 1;
        parteDerecha[8] = 4;
        parteDerecha[9] = 3;
        parteDerecha[10] = 1;
        parteDerecha[11] = 3;

        parteDerecha[12] = 4;
        parteDerecha[13] = 1;
        parteDerecha[14] = 3;
        parteDerecha[15] = 1;
        parteDerecha[16] = 1;

        parteDerecha[17] = 1;
        parteDerecha[18] = 1;
    }

    private int[] error(int linea){
        int tokens[] = new int [18];
        int i = 0;
        for(int l = 0; l < 18; l++){
            if(acciones[linea][l]!=null){
                tokens[i] = l;
                System.out.println(tokens[i]);
                i++;
            }
        }

        int auxTokens[] = new int [i];
        for(int l = 0; l<i; l++){
            auxTokens[l] = tokens[l];
        }
        return auxTokens;
    }

    public void analizar(){
        pila.push(0);
        token = lexico.siguienteToken();
        while(true){
            ///System.out.println(pila);
            Accion accion = acciones[(int)pila.peek()][token.tipo];

            if(accion == null){
                errorSintaxis(error((int)pila.peek()));
            }else {
                if (accion.movimiento == Accion.DESPLAZAMIENTO) {
                    pila.push(accion.dirrecion);
                    token = lexico.siguienteToken();
                } else if(accion.movimiento == Accion.REDUCCION){
                    for(int i = 0; i < parteDerecha[accion.dirrecion]; i++){
                        pila.pop();
                    }
                    pila.push(irA[(int)pila.peek()][parteIzquierda(accion.dirrecion)]);
                } else if(accion.movimiento == Accion.ACEPTAR){
                    break;
                }
            }
        }
        boolean primero = true;
        while (!cadena.isEmpty()) {
            if(primero){
                primero = false;
                System.out.print(cadena.pop());
            }else{
                System.out.print(" "+cadena.pop());
            }
        }
    }

    private void CreacionTabla(){
        acciones[0][Token.FUNCION] = new Accion(Accion.DESPLAZAMIENTO,2);

        /*-----------------------------------------------------------------------------*/

        acciones[1][Token.EOF] = new Accion(Accion.ACEPTAR,-2);
        acciones[2][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,3);
        acciones[3][Token.PYC] = new Accion(Accion.DESPLAZAMIENTO,4);
        acciones[4][Token.BLQ] = new Accion(Accion.DESPLAZAMIENTO,6);

        acciones[5][Token.EOF] = new Accion(Accion.REDUCCION,1);

        /*-----------------------------------------------------------------------------*/

        acciones[6][Token.VAR] = new Accion(Accion.DESPLAZAMIENTO,8);

        acciones[7][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,11);
        acciones[7][Token.BLQ] = new Accion(Accion.DESPLAZAMIENTO,6);
        acciones[7][Token.ESCRIBE] = new Accion(Accion.DESPLAZAMIENTO,12);

        acciones[8][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,16);

        acciones[9][Token.PYC] = new Accion(Accion.DESPLAZAMIENTO,18);
        acciones[9][Token.FBLQ] = new Accion(Accion.DESPLAZAMIENTO,17);

        acciones[10][Token.PYC] = new Accion(Accion.REDUCCION,10);
        acciones[10][Token.FBLQ] = new Accion(Accion.REDUCCION,10);

        /*-----------------------------------------------------------------------------*/

        acciones[11][Token.ASIG] = new Accion(Accion.DESPLAZAMIENTO,19);
        acciones[12][Token.PARI] = new Accion(Accion.DESPLAZAMIENTO,20);

        acciones[13][Token.PYC] = new Accion(Accion.REDUCCION,13);
        acciones[13][Token.FBLQ] = new Accion(Accion.REDUCCION,13);

        acciones[14][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,16);
        acciones[14][Token.FVAR] = new Accion(Accion.DESPLAZAMIENTO,21);

        acciones[15][Token.ID] = new Accion(Accion.REDUCCION,4);
        acciones[15][Token.FVAR] = new Accion(Accion.REDUCCION,4);

        /*-----------------------------------------------------------------------------*/

        acciones[16][Token.DOSP] = new Accion(Accion.DESPLAZAMIENTO,23);

        acciones[17][Token.PYC] = new Accion(Accion.REDUCCION,8);
        acciones[17][Token.FBLQ] = new Accion(Accion.REDUCCION,8);
        acciones[17][Token.EOF] = new Accion(Accion.REDUCCION,8);

        acciones[18][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,11);
        acciones[18][Token.BLQ] = new Accion(Accion.DESPLAZAMIENTO,6);
        acciones[18][Token.ESCRIBE] = new Accion(Accion.DESPLAZAMIENTO,12);

        acciones[19][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,29);
        acciones[19][Token.NUMENTERO] = new Accion(Accion.DESPLAZAMIENTO,27);
        acciones[19][Token.NUMREAL] = new Accion(Accion.DESPLAZAMIENTO,28);

        acciones[20][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,29);
        acciones[20][Token.NUMENTERO] = new Accion(Accion.DESPLAZAMIENTO,27);
        acciones[20][Token.NUMREAL] = new Accion(Accion.DESPLAZAMIENTO,28);

        /*-----------------------------------------------------------------------------*/

        acciones[21][Token.ID] = new Accion(Accion.REDUCCION,2);
        acciones[21][Token.BLQ] = new Accion(Accion.REDUCCION,2);
        acciones[21][Token.ESCRIBE] = new Accion(Accion.REDUCCION,2);

        acciones[22][Token.ID] = new Accion(Accion.REDUCCION,3);
        acciones[22][Token.FVAR] = new Accion(Accion.REDUCCION,3);

        acciones[23][Token.ENTERO] = new Accion(Accion.DESPLAZAMIENTO,32);
        acciones[23][Token.REAL] = new Accion(Accion.DESPLAZAMIENTO,33);

        acciones[24][Token.PYC] = new Accion(Accion.REDUCCION,9);
        acciones[24][Token.FBLQ] = new Accion(Accion.REDUCCION,9);

        acciones[25][Token.PYC] = new Accion(Accion.REDUCCION,11);
        acciones[25][Token.FBLQ] = new Accion(Accion.REDUCCION,11);
        acciones[25][Token.OPAS] = new Accion(Accion.DESPLAZAMIENTO,34);

        /*-----------------------------------------------------------------------------*/

        acciones[26][Token.PYC] = new Accion(Accion.REDUCCION,15);
        acciones[26][Token.FBLQ] = new Accion(Accion.REDUCCION,15);
        acciones[26][Token.PARD] = new Accion(Accion.REDUCCION,15);
        acciones[26][Token.OPAS] = new Accion(Accion.REDUCCION,15);

        acciones[27][Token.PYC] = new Accion(Accion.REDUCCION,16);
        acciones[27][Token.FBLQ] = new Accion(Accion.REDUCCION,16);
        acciones[27][Token.PARD] = new Accion(Accion.REDUCCION,16);
        acciones[27][Token.OPAS] = new Accion(Accion.REDUCCION,16);

        acciones[28][Token.PYC] = new Accion(Accion.REDUCCION,17);
        acciones[28][Token.FBLQ] = new Accion(Accion.REDUCCION,17);
        acciones[28][Token.PARD] = new Accion(Accion.REDUCCION,17);
        acciones[28][Token.OPAS] = new Accion(Accion.REDUCCION,17);

        acciones[29][Token.PYC] = new Accion(Accion.REDUCCION,18);
        acciones[29][Token.FBLQ] = new Accion(Accion.REDUCCION,18);
        acciones[29][Token.PARD] = new Accion(Accion.REDUCCION,18);
        acciones[29][Token.OPAS] = new Accion(Accion.REDUCCION,18);

        acciones[30][Token.PARD] = new Accion(Accion.DESPLAZAMIENTO,35);
        acciones[30][Token.OPAS] = new Accion(Accion.DESPLAZAMIENTO,34);

        /*-----------------------------------------------------------------------------*/

        acciones[31][Token.PYC] = new Accion(Accion.DESPLAZAMIENTO,36);
        acciones[32][Token.PYC] = new Accion(Accion.REDUCCION,6);
        acciones[33][Token.PYC] = new Accion(Accion.REDUCCION,7);

        acciones[34][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,29);
        acciones[34][Token.NUMENTERO] = new Accion(Accion.DESPLAZAMIENTO,27);
        acciones[34][Token.NUMREAL] = new Accion(Accion.DESPLAZAMIENTO,28);

        acciones[35][Token.PYC] = new Accion(Accion.REDUCCION,12);
        acciones[35][Token.FBLQ] = new Accion(Accion.REDUCCION,12);

        /*-----------------------------------------------------------------------------*/

        acciones[36][Token.ID] = new Accion(Accion.REDUCCION,5);
        acciones[36][Token.FVAR] = new Accion(Accion.REDUCCION,5);

        acciones[37][Token.PYC] = new Accion(Accion.REDUCCION,14);
        acciones[37][Token.FBLQ] = new Accion(Accion.REDUCCION,14);
        acciones[37][Token.PARD] = new Accion(Accion.REDUCCION,14);
        acciones[37][Token.OPAS] = new Accion(Accion.REDUCCION,14);
    }

    void irATabla(){
        irA[0][S] = 1;

        irA[4][B] = 5;
        irA[6][D] = 7;

        irA[7][B] = 13;
        irA[7][SI] = 9;
        irA[7][I] = 10;

        irA[8][L] = 14;
        irA[8][V] = 15;

        irA[14][V] = 22;

        irA[18][B] = 13;
        irA[18][I] = 24;

        irA[19][E] = 25;
        irA[19][F] = 26;

        irA[20][E] = 30;
        irA[20][F] = 26;

        irA[23][TIPO] = 31;

        irA[34][F] = 37;
    }

    private void errorSintaxis(int[] tokEsperado) {
        TreeSet<Integer> errores = new TreeSet<Integer>();
        if (token.tipo != Token.EOF) {
            System.err.print("Error sintactico (" + token.columna + ","
                    + token.fila + "): encontrado '" + token.lexema + "'" + ", esperaba");
        }
        else {
            System.err.print("Error sintactico: encontrado fin de fichero, esperaba");
        }
        for (int i = 0; i< tokEsperado.length; i++) {
            errores.add(tokEsperado[i]);
        }
        for (int tipo: errores){
            System.err.print(" " + Token.nombreToken.get(tipo));
        }
        System.err.println();
        System.exit(-1);
    }

    public void comprobarFinFichero() {
        if (token.tipo != Token.EOF) {
            int [] tokens = new int[1];
            tokens[0] = Token.EOF;
            errorSintaxis(tokens);
        }else if(flag){
            System.out.print(cadena);
        }
    }
}


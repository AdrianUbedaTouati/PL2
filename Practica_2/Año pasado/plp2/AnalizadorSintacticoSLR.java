import java.util.EmptyStackException;
import java.util.Stack;
import java.util.TreeSet;

public class AnalizadorSintacticoSLR {

    //48 estados con 22 tipos
    private Accion acciones[][] = new Accion[48][22];
    private int irA [][] = new int[48][12];
    private int parteDerecha [] = new int[23];

    private Stack pila = new Stack();

    private Stack resultado = new Stack();
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

    private int parteIzquierda(int i){
        if(i==1){
            return IrA.S;
        }else if(i==2 || i==3){
            return IrA.VSP;
        }else if(i==4){
            return IrA.UNSP;
        }else if(i==5 || i==6){
            return IrA.LV;
        }else if(i==7){
            return IrA.V;
        }else if(i==8 || i==9){
            return IrA.TIPO;
        }else if(i==10){
            return IrA.BLOQUE;
        }else if(i==11 || i==12){
            return IrA.SINSTR;
        }else if(i==13 || i==14 || i==15 || i==16 || i==17){
            return IrA.INSTR;
        }else if(i==18 || i==19){
            return IrA.E;
        }else {
            return IrA.FACTOR;
        }
    }

    private class IrA {
        private static final int
                X = 0,
                S = 1,
                VSP = 2,
                UNSP = 3,
                LV = 4,
                V = 5,
                TIPO = 6,
                BLOQUE = 7,
                SINSTR = 8,
                INSTR = 9,
                E = 10,
                FACTOR = 11;
    }
    private Token token;
    private AnalizadorLexico lexico;
    private boolean flag;
    private StringBuilder cadena = new StringBuilder();

    AnalizadorSintacticoSLR(AnalizadorLexico al){
        flag = true;
        lexico = al;
        ParteDerechaTabla();
        CreacionTabla();
        irATabla();
        //token = lexico.siguienteToken();
    }

    private int[] error(int linea){
        int tokens[] = new int [22];
        int i = 0;
        for(int l = 0; l < 22; l++){
            if(acciones[linea][l]!=null){
                tokens[i] = l;
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
                    resultado.push(accion.dirrecion);
                } else if(accion.movimiento == Accion.ACEPTAR){
                    if(flag && resultado.size() >= 1) {
                        System.out.print(resultado.peek());
                        resultado.pop();
                        int longitud = resultado.size();
                        for (int i = 0; i < longitud; i++) {
                            System.out.print(" "+resultado.peek());
                            resultado.pop();
                        }
                    }
                    break;
                }
            }
        }
    }

    private void CreacionTabla(){
        acciones[0][Token.ALGORITMO] = new Accion(Accion.DESPLAZAMIENTO,2);

        /*-----------------------------------------------------------------------------*/

        acciones[1][Token.EOF] = new Accion(Accion.ACEPTAR,-2);
        acciones[2][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,3);
        acciones[3][Token.PYC] = new Accion(Accion.DESPLAZAMIENTO,4);
        acciones[4][Token.VAR] = new Accion(Accion.DESPLAZAMIENTO,7);

        acciones[5][Token.VAR] = new Accion(Accion.DESPLAZAMIENTO,7);
        acciones[5][Token.BLQ] = new Accion(Accion.DESPLAZAMIENTO,10);

        /*-----------------------------------------------------------------------------*/

        acciones[6][Token.VAR] = new Accion(Accion.REDUCCION,3);
        acciones[6][Token.BLQ] = new Accion(Accion.REDUCCION,3);

        acciones[7][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,13);
        acciones[8][Token.EOF] = new Accion(Accion.REDUCCION,1);

        acciones[9][Token.VAR] = new Accion(Accion.REDUCCION,2);
        acciones[9][Token.BLQ] = new Accion(Accion.REDUCCION,2);

        acciones[10][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,17);
        acciones[10][Token.BLQ] = new Accion(Accion.DESPLAZAMIENTO,10);
        acciones[10][Token.SI] = new Accion(Accion.DESPLAZAMIENTO,18);
        acciones[10][Token.MIENTRAS] = new Accion(Accion.DESPLAZAMIENTO,19);
        acciones[10][Token.ESCRIBIR] = new Accion(Accion.DESPLAZAMIENTO,20);

        /*-----------------------------------------------------------------------------*/

        acciones[11][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,13);
        acciones[11][Token.VAR] = new Accion(Accion.REDUCCION,4);
        acciones[11][Token.BLQ] = new Accion(Accion.REDUCCION,4);

        acciones[12][Token.ID] = new Accion(Accion.REDUCCION,6);
        acciones[12][Token.VAR] = new Accion(Accion.REDUCCION,6);
        acciones[12][Token.BLQ] = new Accion(Accion.REDUCCION,6);

        acciones[13][Token.DOSP] = new Accion(Accion.DESPLAZAMIENTO,22);

        acciones[14][Token.PYC] = new Accion(Accion.DESPLAZAMIENTO,24);
        acciones[14][Token.FBLQ] = new Accion(Accion.DESPLAZAMIENTO,23);

        acciones[15][Token.PYC] = new Accion(Accion.REDUCCION,12);
        acciones[15][Token.FBLQ] = new Accion(Accion.REDUCCION,12);

        /*-----------------------------------------------------------------------------*/

        acciones[16][Token.PYC] = new Accion(Accion.REDUCCION,13);
        acciones[16][Token.FBLQ] = new Accion(Accion.REDUCCION,13);
        acciones[16][Token.FSI] = new Accion(Accion.REDUCCION,13);

        acciones[17][Token.ASIG] = new Accion(Accion.DESPLAZAMIENTO,25);

        acciones[18][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,28);
        acciones[18][Token.NENTERO] = new Accion(Accion.DESPLAZAMIENTO,29);
        acciones[18][Token.NREAL] = new Accion(Accion.DESPLAZAMIENTO,30);

        acciones[19][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,28);
        acciones[19][Token.NENTERO] = new Accion(Accion.DESPLAZAMIENTO,29);
        acciones[19][Token.NREAL] = new Accion(Accion.DESPLAZAMIENTO,30);

        acciones[20][Token.PARI] = new Accion(Accion.DESPLAZAMIENTO,32);

        /*-----------------------------------------------------------------------------*/

        acciones[21][Token.ID] = new Accion(Accion.REDUCCION,5);
        acciones[21][Token.VAR] = new Accion(Accion.REDUCCION,5);
        acciones[21][Token.BLQ] = new Accion(Accion.REDUCCION,5);

        acciones[22][Token.ENTERO] = new Accion(Accion.DESPLAZAMIENTO,34);
        acciones[22][Token.REAL] = new Accion(Accion.DESPLAZAMIENTO,35);

        acciones[23][Token.PYC] = new Accion(Accion.REDUCCION,10);
        acciones[23][Token.FBLQ] = new Accion(Accion.REDUCCION,10);
        acciones[23][Token.FSI] = new Accion(Accion.REDUCCION,10);
        acciones[23][Token.EOF] = new Accion(Accion.REDUCCION,10);

        acciones[24][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,17);
        acciones[24][Token.BLQ] = new Accion(Accion.DESPLAZAMIENTO,10);
        acciones[24][Token.SI] = new Accion(Accion.DESPLAZAMIENTO,18);
        acciones[24][Token.MIENTRAS] = new Accion(Accion.DESPLAZAMIENTO,19);
        acciones[24][Token.ESCRIBIR] = new Accion(Accion.DESPLAZAMIENTO,20);

        acciones[25][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,28);
        acciones[25][Token.NENTERO] = new Accion(Accion.DESPLAZAMIENTO,29);
        acciones[25][Token.NREAL] = new Accion(Accion.DESPLAZAMIENTO,30);

        /*-----------------------------------------------------------------------------*/

        acciones[26][Token.ENTONCES] = new Accion(Accion.DESPLAZAMIENTO,38);
        acciones[26][Token.OPAS] = new Accion(Accion.DESPLAZAMIENTO,39);

        acciones[27][Token.PYC] = new Accion(Accion.REDUCCION,19);
        acciones[27][Token.FBLQ] = new Accion(Accion.REDUCCION,19);
        acciones[27][Token.ENTONCES] = new Accion(Accion.REDUCCION,19);
        acciones[27][Token.FSI] = new Accion(Accion.REDUCCION,19);
        acciones[27][Token.HACER] = new Accion(Accion.REDUCCION,19);
        acciones[27][Token.PARD] = new Accion(Accion.REDUCCION,19);
        acciones[27][Token.OPAS] = new Accion(Accion.REDUCCION,19);

        acciones[28][Token.PYC] = new Accion(Accion.REDUCCION,20);
        acciones[28][Token.FBLQ] = new Accion(Accion.REDUCCION,20);
        acciones[28][Token.ENTONCES] = new Accion(Accion.REDUCCION,20);
        acciones[28][Token.FSI] = new Accion(Accion.REDUCCION,20);
        acciones[28][Token.HACER] = new Accion(Accion.REDUCCION,20);
        acciones[28][Token.PARD] = new Accion(Accion.REDUCCION,20);
        acciones[28][Token.OPAS] = new Accion(Accion.REDUCCION,20);

        acciones[29][Token.PYC] = new Accion(Accion.REDUCCION,21);
        acciones[29][Token.FBLQ] = new Accion(Accion.REDUCCION,21);
        acciones[29][Token.ENTONCES] = new Accion(Accion.REDUCCION,21);
        acciones[29][Token.FSI] = new Accion(Accion.REDUCCION,21);
        acciones[29][Token.HACER] = new Accion(Accion.REDUCCION,21);
        acciones[29][Token.PARD] = new Accion(Accion.REDUCCION,21);
        acciones[29][Token.OPAS] = new Accion(Accion.REDUCCION,21);

        acciones[30][Token.PYC] = new Accion(Accion.REDUCCION,22);
        acciones[30][Token.FBLQ] = new Accion(Accion.REDUCCION,22);
        acciones[30][Token.ENTONCES] = new Accion(Accion.REDUCCION,22);
        acciones[30][Token.FSI] = new Accion(Accion.REDUCCION,22);
        acciones[30][Token.HACER] = new Accion(Accion.REDUCCION,22);
        acciones[30][Token.PARD] = new Accion(Accion.REDUCCION,22);
        acciones[30][Token.OPAS] = new Accion(Accion.REDUCCION,22);

        /*-----------------------------------------------------------------------------*/

        acciones[31][Token.HACER] = new Accion(Accion.DESPLAZAMIENTO,40);
        acciones[31][Token.OPAS] = new Accion(Accion.DESPLAZAMIENTO,39);

        acciones[32][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,28);
        acciones[32][Token.NENTERO] = new Accion(Accion.DESPLAZAMIENTO,29);
        acciones[32][Token.NREAL] = new Accion(Accion.DESPLAZAMIENTO,30);

        acciones[33][Token.PYC] = new Accion(Accion.DESPLAZAMIENTO,42);

        acciones[34][Token.PYC] = new Accion(Accion.REDUCCION,8);

        acciones[35][Token.PYC] = new Accion(Accion.REDUCCION,9);

        /*-----------------------------------------------------------------------------*/

        acciones[36][Token.PYC] = new Accion(Accion.REDUCCION,11);
        acciones[36][Token.FBLQ] = new Accion(Accion.REDUCCION,11);

        acciones[37][Token.PYC] = new Accion(Accion.REDUCCION,14);
        acciones[37][Token.FBLQ] = new Accion(Accion.REDUCCION,14);
        acciones[37][Token.FSI] = new Accion(Accion.REDUCCION,14);
        acciones[37][Token.OPAS] = new Accion(Accion.DESPLAZAMIENTO,39);

        acciones[38][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,17);
        acciones[38][Token.BLQ] = new Accion(Accion.DESPLAZAMIENTO,10);
        acciones[38][Token.SI] = new Accion(Accion.DESPLAZAMIENTO,18);
        acciones[38][Token.MIENTRAS] = new Accion(Accion.DESPLAZAMIENTO,19);
        acciones[38][Token.ESCRIBIR] = new Accion(Accion.DESPLAZAMIENTO,20);

        acciones[39][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,28);
        acciones[39][Token.NENTERO] = new Accion(Accion.DESPLAZAMIENTO,29);
        acciones[39][Token.NREAL] = new Accion(Accion.DESPLAZAMIENTO,30);

        acciones[40][Token.ID] = new Accion(Accion.DESPLAZAMIENTO,17);
        acciones[40][Token.BLQ] = new Accion(Accion.DESPLAZAMIENTO,10);
        acciones[40][Token.SI] = new Accion(Accion.DESPLAZAMIENTO,18);
        acciones[40][Token.MIENTRAS] = new Accion(Accion.DESPLAZAMIENTO,19);
        acciones[40][Token.ESCRIBIR] = new Accion(Accion.DESPLAZAMIENTO,20);

        /*-----------------------------------------------------------------------------*/

        acciones[41][Token.PARD] = new Accion(Accion.DESPLAZAMIENTO,46);
        acciones[41][Token.OPAS] = new Accion(Accion.DESPLAZAMIENTO,39);

        acciones[42][Token.ID] = new Accion(Accion.REDUCCION,7);
        acciones[42][Token.VAR] = new Accion(Accion.REDUCCION,7);
        acciones[42][Token.BLQ] = new Accion(Accion.REDUCCION,7);

        acciones[43][Token.FSI] = new Accion(Accion.DESPLAZAMIENTO,47);

        acciones[44][Token.PYC] = new Accion(Accion.REDUCCION,18);
        acciones[44][Token.FBLQ] = new Accion(Accion.REDUCCION,18);
        acciones[44][Token.ENTONCES] = new Accion(Accion.REDUCCION,18);
        acciones[44][Token.FSI] = new Accion(Accion.REDUCCION,18);
        acciones[44][Token.HACER] = new Accion(Accion.REDUCCION,18);
        acciones[44][Token.PARD] = new Accion(Accion.REDUCCION,18);
        acciones[44][Token.OPAS] = new Accion(Accion.REDUCCION,18);

        acciones[45][Token.PYC] = new Accion(Accion.REDUCCION,16);
        acciones[45][Token.FBLQ] = new Accion(Accion.REDUCCION,16);
        acciones[45][Token.FSI] = new Accion(Accion.REDUCCION,16);

        /*-----------------------------------------------------------------------------*/

        acciones[46][Token.PYC] = new Accion(Accion.REDUCCION,17);
        acciones[46][Token.FBLQ] = new Accion(Accion.REDUCCION,17);
        acciones[46][Token.FSI] = new Accion(Accion.REDUCCION,17);

        acciones[47][Token.PYC] = new Accion(Accion.REDUCCION,15);
        acciones[47][Token.FBLQ] = new Accion(Accion.REDUCCION,15);
        acciones[47][Token.FSI] = new Accion(Accion.REDUCCION,15);
    }

    void ParteDerechaTabla(){
        parteDerecha[1] = 5;

        parteDerecha[2] = 2;
        parteDerecha[3] = 1;
        parteDerecha[4] = 2;
        parteDerecha[5] = 2;
        parteDerecha[6] = 1;

        parteDerecha[7] = 4;
        parteDerecha[8] = 1;
        parteDerecha[9] = 1;
        parteDerecha[10] = 3;
        parteDerecha[11] = 3;

        parteDerecha[12] = 1;
        parteDerecha[13] = 1;
        parteDerecha[14] = 3;
        parteDerecha[15] = 5;
        parteDerecha[16] = 4;

        parteDerecha[17] = 4;
        parteDerecha[18] = 3;
        parteDerecha[19] = 1;
        parteDerecha[20] = 1;
        parteDerecha[21] = 1;

        parteDerecha[22] = 1;
    }

    void irATabla(){
        irA[0][IrA.S] = 1;

        irA[4][IrA.VSP] = 5;
        irA[4][IrA.UNSP] = 6;

        irA[5][IrA.UNSP] = 9;
        irA[5][IrA.BLOQUE] = 8;

        irA[7][IrA.LV] = 11;
        irA[7][IrA.V] = 12;

        irA[10][IrA.BLOQUE] = 16;
        irA[10][IrA.SINSTR] = 14;
        irA[10][IrA.INSTR] = 15;

        irA[11][IrA.V] = 21;

        irA[18][IrA.E] = 26;
        irA[18][IrA.FACTOR] = 27;

        irA[19][IrA.E] = 31;
        irA[19][IrA.FACTOR] = 27;

        irA[22][IrA.TIPO] = 33;

        irA[24][IrA.BLOQUE] = 16;
        irA[24][IrA.INSTR] = 36;

        irA[25][IrA.E] = 37;
        irA[25][IrA.FACTOR] = 27;

        irA[32][IrA.E] = 41;
        irA[32][IrA.FACTOR] = 27;

        irA[38][IrA.BLOQUE] = 16;
        irA[38][IrA.INSTR] = 43;

        irA[39][IrA.FACTOR] = 44;

        irA[40][IrA.BLOQUE] = 16;
        irA[40][IrA.INSTR] = 45;
    }

    private void errorSintaxis(int[] tokEsperado) {
        TreeSet<Integer> errores = new TreeSet<Integer>();
        if (token.tipo != Token.EOF) {
            System.err.print("Error sintactico (" + token.fila + ","
                    + token.columna + "): encontrado '" + token.lexema + "'" + ", esperaba");
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


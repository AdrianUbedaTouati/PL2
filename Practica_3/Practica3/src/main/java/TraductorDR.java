public class TraductorDR {
    private final int ERRYADECL=1,ERRNOMFUNC=2,ERRNOSIMPLE=3,ERRNODECL=4,ERRTIPOS=5,ERRNOENTEROIZQ=6,ERRNOENTERODER=7,ERRRANGO=8;
    private void errorSemantico(int nerror,Token tok)
    {
        System.err.print("Error semantico ("+tok.fila+","+tok.columna+"): en '"+tok.lexema+"', ");
        switch (nerror) {
            case ERRYADECL: System.err.println("ya existe en este ambito");
                break;
            case ERRNOMFUNC: System.err.println("no puede llamarse igual que la funcion");
                break;
            case ERRNOSIMPLE: System.err.println("debe ser de tipo entero o real");
                break;
            case ERRNODECL: System.err.println("no ha sido declarado");
                break;
            case ERRTIPOS: System.err.println("tipos incompatibles entero/real");
                break;
            case ERRNOENTEROIZQ: System.err.println("el operando izquierdo debe ser entero");
                break;
            case ERRNOENTERODER: System.err.println("el operando derecho debe ser entero");
                break;
            case ERRRANGO: System.err.println("rango incorrecto");
                break;
        }
        System.exit(-1);
    }
}

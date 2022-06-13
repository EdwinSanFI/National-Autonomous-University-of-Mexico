package Awards;
import java.util.Random;

public class PullLever {
    Cherry cherry = new Cherry();
    RedDice redDice = new RedDice();
    Diamond diamond = new Diamond();
    Watermelon watermelon = new Watermelon();
    Seven seven = new Seven();
    Clover clover = new Clover();
    Grape grape = new Grape();
    Random random = new Random();
    int creditos;
    /** For color */
    final String RESET = "\u001B[0m";

    /**
     * 
     * @return the credits won
     */
    public int play(){

        /** Score of the user */
        int score = 0;
        /** Roulette */
        Awards[][] roulette = new Awards[3][5];

        /** Asigna valores aleatorios */
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                int valor = random.nextInt(0, 101);
                /** 5% */
                if (valor >= 0 && valor <= 5) {
                    roulette[i][j] = redDice.clone();
                /** 10% */
                } else if (valor > 5 && valor <= 15) {
                    roulette[i][j] = seven.clone();
                /** 15% */
                } else if (valor > 15 && valor <= 25) {
                    roulette[i][j] = diamond.clone();
                /** 15% */
                } else if (valor > 25 && valor <= 45) {
                    roulette[i][j] = clover.clone();
                /** 15% */
                } else if (valor > 45 && valor <= 60) {
                    roulette[i][j] = cherry.clone();
                /** 20% */
                } else if (valor > 60 && valor <= 80) {
                    roulette[i][j] = watermelon.clone();
                /** 20% */
                } else if (valor > 80 && valor <= 100) {
                    roulette[i][j] = grape.clone();
                }
            }
        }


        /** Pruebas */

        // roulette[0][0] = redDice.clone();
        // roulette[1][1] = redDice.clone();
        // roulette[2][2] = redDice.clone();
        // roulette[1][3] = redDice.clone();
        // roulette[0][4] = redDice.clone();


        creditos = revisarLinea(score, roulette);

        printRoulette(roulette, RESET);
        /** Lo puse despues para que al imprimir aparezcan aquellos espacios ganadores */
        return creditos;
    }

    /** Print the roulette */
    public void printRoulette(Awards roulette[][], String reset){
        System.out.println("\n");
        /** Print each line */
        for (int i = 0; i < 3; i++) {
            System.out.print(" | ");
            /** Print each column */
            for (int j = 0; j < 5; j++) {
                System.out.print(roulette[i][j].getColor() + roulette[i][j].getName() + reset +" | ");
            }
            System.out.println();
        }

    }

    /** Revisa que linea de premio hay */
    public int revisarLinea(int score, Awards roulette[][]){
        String PURPLE = "\033[35m";
        String RED = "\033[31m";
        String BLUE = "\033[34m";
        String YELLOW = "\033[33m";
        String GREEN = "\033[32m";

        /** Checking if there is a line with a award */
        for(int i = 0; i < 3; i++){
            /** If the fist object is the same as the second && the second is the same as the third */
            if(roulette[i][0].getNameString().equals(roulette[i][1].getNameString()) && roulette[i][0].getNameString().equals(roulette[i][2].getNameString())){
                /** If the third object is the same as the fourth */
                if (roulette[i][2].getNameString().equals(roulette[i][3].getNameString())){
                    /** If the fourth object is the same as the fifth */
                    if(roulette[i][3].getNameString().equals(roulette[i][4].getNameString())){
                        /** Paint the 5 objects with the same color */
                        roulette[i][0].setColor(BLUE);
                        roulette[i][1].setColor(BLUE);
                        roulette[i][2].setColor(BLUE);
                        roulette[i][3].setColor(BLUE);
                        roulette[i][4].setColor(BLUE);
                        /** Add the credits won after got 5 objects on the same line */
                        score += roulette[i][4].getFive();
                        continue;
                    } else{
                        /** Paint the 4 objects with the same color */
                        roulette[i][0].setColor(YELLOW);
                        roulette[i][1].setColor(YELLOW);
                        roulette[i][2].setColor(YELLOW);
                        roulette[i][3].setColor(YELLOW);
                        /** Add the credits won after got 4 objects on the same line */
                        score += roulette[i][3].getFour();
                        continue;
                    }
                }
                /** Paint the 3 objects with the same color */
                roulette[i][0].setColor(RED);
                roulette[i][1].setColor(RED);
                roulette[i][2].setColor(RED);
                /** Add the credits won after got 3 objects on the same line */
                score += roulette[i][0].getThree();
            }
        }

        /** Fourth line of award */
        /** If the [2][0] obectj is the same as the [1][1] && the [1][1] is the same as the [0][2] */
        if (roulette[2][0].getNameString().equals(roulette[1][1].getNameString()) && roulette[1][1].getNameString().equals(roulette[0][2].getNameString()) ) {
            /** If the [0][2] object is the same as the [1][3] */
            if(roulette[0][2].getNameString().equals(roulette[1][3].getNameString())) {
                /** If the [1][3] object is the same as the [2][4] */
                if(roulette[1][3].getNameString().equals(roulette[2][4].getNameString())) {
                    /** Paint the 5 objects with the same color */
                    roulette[2][0].setColor(PURPLE);
                    roulette[1][1].setColor(PURPLE);
                    roulette[0][2].setColor(PURPLE);
                    roulette[1][3].setColor(PURPLE);
                    roulette[2][4].setColor(PURPLE);
                    /** Add the credits won after got 5 objects */
                    score += roulette[2][4].getFive();
                } else {
                    /** Paint the 4 objects with the same color */
                    roulette[2][0].setColor(PURPLE);
                    roulette[1][1].setColor(PURPLE);
                    roulette[0][2].setColor(PURPLE);
                    roulette[1][3].setColor(PURPLE);
                    /** Add the credits won after got 4 objects */
                    score += roulette[1][3].getFour();
                }
            } else {
                /** Paint the 3 objects with the same color */
                roulette[2][0].setColor(PURPLE);
                roulette[1][1].setColor(PURPLE);
                roulette[0][2].setColor(PURPLE);
                /** Add the credits won after got 3 objects */
                score += roulette[0][2].getThree();
            }
        }

        /** Fifth line of award */
        /** If the [0][0] object is the same as the [1][1] && the [1][1] is the same as the [2][2] */
        if (roulette[0][0].getNameString().equals(roulette[1][1].getNameString()) && roulette[1][1].getNameString().equals(roulette[2][2].getNameString()) ) {
            /** If the [2][2] object is the same as the [1][3] */
            if(roulette[2][2].getNameString().equals(roulette[1][3].getNameString())){
                /** If the [1][3] object is the same as the [0][4] */
                if(roulette[1][3].getNameString().equals(roulette[0][4].getNameString())){
                    /** Paint the 5 objects with the same color */
                    roulette[0][4].setColor(GREEN);
                    roulette[0][0].setColor(GREEN);
                    roulette[1][1].setColor(GREEN);
                    roulette[2][2].setColor(GREEN);
                    roulette[1][3].setColor(GREEN);
                    /** Add the credits won after got 5 objects */
                    score += roulette[0][4].getFive();
                } else {
                    /** Paint the 4 objects with the same color */
                    roulette[0][0].setColor(GREEN);
                    roulette[1][1].setColor(GREEN);
                    roulette[2][2].setColor(GREEN);
                    roulette[1][3].setColor(GREEN);
                    /** Add the credits won after got 4 objects */
                    score += roulette[1][3].getFour();
                }
            } else {
                /** Paint the 3 objects with the same color */
                roulette[0][0].setColor(GREEN);
                roulette[1][1].setColor(GREEN);
                roulette[2][2].setColor(GREEN);
                /** Add the credits won after got 3 objects */
                score += roulette[2][2].getThree();
            }
        }

        return score;
    }
}

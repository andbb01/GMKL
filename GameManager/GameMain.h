#include "../Types.h"

/** 
 * Insieme di funzioni necessarie per l'utilizzo del GameMain automatico
 * Viene automaticamente creato un main che esegue il setup iniziale tramite funzione gameMain::gameSetup() ed esegue ciclicamente gameMain::gameLoop()
 * Definire GAME_MAIN in fase di compilazione per usare questa namespace
 */
namespace gameMain{
    /**
     * @fn void gameSetup();
     * Funzione eseguita all'avvio del main dove si inizializzano tutte le variabili, oggetti etc., è necessario definirla per usare il main predefinito
     */
    void gameSetup();
    /** 
     * @fn void gameLoop();
     * Funzione eseguita ciclicamente dal main, è necessario definirla per usare il main predefinito
     */
    void gameLoop();
}

int main(){

    gameMain::gameSetup();

    while(1){
        gameMain::gameLoop();
    }
    return 0;
}
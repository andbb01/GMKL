#include "../Types.h"
#include "WindowManager.h"
/** 
 * Insieme di funzioni necessarie per l'utilizzo del GameMain automatico
 * Viene automaticamente creato un main che esegue il setup iniziale tramite funzione gameMain::gameSetup() ed esegue ciclicamente gameMain::gameLoop()
 * il main si interrompe automaticamente quando la condizione gameMain::exitCondition() è verificata (leggere le descrizioni delle funzioni)
 * Il main aggiorna automaticamente lo stato degli eventi della finestra in WindowManager
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
    /**
     * @fn bool exitCondition();
     * (In fase di test) Funzione per il controllo della condizione di uscita nel gameMain
     */
    bool exitCondition();
}

int main(){

    gameMain::gameSetup();

    while(!gameMain::exitCondition()){
        gameMain::gameLoop();

        WindowManager::updateEvent();
    }
    return 0;
}
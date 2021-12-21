# GMKL
La Libreria GMKL è un insieme di classi e metodi necessari per la programmazione di videogiochi, in particolare si hanno classi per la gestione della grafica (Graphics), classi per la gestione degli oggetti di gioco (GamaObject, PgysicsObject e TextObject), classi per la gestione di input da periferiche (MouseManager, KayboardManager) e classi per la gestione generica di tutte le altre funzionalità che si potrebbero volere (audio, eventi della finestra, etc.)
L'intera libreria si basa su <a href="https://www.libsdl.org/">SDL</a> (versione 2) e questa sarà necessaria in fase di compilazione (compreso linking della libreria).
<h3>Gestione tramite GameMain</h3>
GameMain è un namespace contenente il prototipo di 3 funzioni:
<ol>
<li>gameMain::gameSetup()</li>
<li>gameMain::gameLoop()</li>
<li>gameMain::exitCondition()</li>
</ol>
Se si utilizza il namespace gameMain, aggiungendo #define GAME_MAIN nel codice prima di includere la libreria o definendolo in fase di compilazione (-D GAME_MAIN), la libreria provvederà autonomamente a definire un main che eseguirà un setup tramite la funzione gameMain::gameSetup() e successivamente eseguirà ciclicamente, fino al verificarsi della condizione imposta da gameMain::exitCondition(), la funzione gameMain::gameLoop().
L'utilizzatore della libreria dovrà implementare le funzioni sopra descritte per utilizzare l'opzione GAME_MAIN ed evitare errori di compilazione (poichè esse sono già definite ma non implementate.
Per maggiori informazioni consultare la <a href="http://dispenser.rf.gd/GMKL-Doc/index.html">documentazione</a>

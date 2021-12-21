<img src="http://dispenser.rf.gd/GMKL-Doc/GMKL_logo.png">
La Libreria GMKL è un insieme di classi e metodi necessari per la programmazione di videogiochi, in particolare si hanno classi per la gestione della grafica (Graphics), classi per la gestione degli oggetti di gioco (GamaObject, PgysicsObject e TextObject), classi per la gestione di input da periferiche (MouseManager, KayboardManager) e classi per la gestione generica di tutte le altre funzionalità che si potrebbero volere (audio, eventi della finestra, etc.)
L'intera libreria si basa su <a href="https://www.libsdl.org/">SDL</a> (versione 2) e questa sarà necessaria in fase di compilazione (compreso linking della libreria).
Qui si presenta un breve riassunto delle varie classi con l'organizzazione logica che è stata seguita durante lo sviluppo.
Per maggiori informazioni consultare la <a href="http://dispenser.rf.gd/GMKL-Doc/index.html">documentazione</a>
<h2>Classi basilari</h3>
Le classi che si sono scelti di definire basilari sono Point e Rect vista la lorio ovvietà ddi implementazione.
La classe <strong>Point</strong> è composta da due coordinate (x, y) e definisce un costruttore con coordinate specifiche e uno a coordinate nulle (si fa presente che SDL usa un sistema carteziano con asse y verso il bassi).
Similarmente alla classe vector effettua override di operazione somma e sottrazione per semplificare queste operazioni tra i punti.
la classe <strong>Rect</strong> è definita da un vertice (Point), una largezza e un'altezza le funzioni base sono analoghe a quelle di Point, in più contiene un metodo che ricevuto in ingresso un punto ci dice se questo è contenuto nel rettangolo.
<h2>Classi GameManager</h3>
In questa sezioni di classi sono contenute la opzioni di GameMain, AudioManager, KeyboardManager, MouseManager e WindowManager, tutte le classi di questia sezione non sono istanziabili ma sarà solo necessario utilizzare i loro metodi statici.
<h3>GameMain</h3>
GameMain è un namespace contenente il prototipo di 3 funzioni:
<ol>
<li>gameMain::gameSetup()</li>
<li>gameMain::gameLoop()</li>
<li>gameMain::exitCondition()</li>
</ol>
Se si utilizza il namespace gameMain, aggiungendo #define GAME_MAIN nel codice prima di includere la libreria o definendolo in fase di compilazione (-D GAME_MAIN), la libreria provvederà autonomamente a definire un main che eseguirà un setup tramite la funzione gameMain::gameSetup() e successivamente eseguirà ciclicamente, fino al verificarsi della condizione imposta da gameMain::exitCondition(), la funzione gameMain::gameLoop().
L'utilizzatore della libreria dovrà implementare le funzioni sopra descritte per utilizzare l'opzione GAME_MAIN ed evitare errori di compilazione (poichè esse sono già definite ma non implementate).
<h3>AudioManager</h3>
La classe AudioManager comprende un insieme di metodi necessari per l'utilizzo dell'audio, in particolare si distinguono le musiche e gli effetti sonori (solitamente i file degli effetti saranno di tipo wav e i file delle musiche di tipo mp3 o simili), all'interno di questa classe sarà possibile avviare e stoppare musiche, avviare effetti sonori, cambiare il volume di musiche ed effetti. Per utilizzare la classe non è necessario istanziare un oggetto ma e sufficiente chiamare i metodi (poichè sono tutti metodi statici). 
<h3>KeyboardManager</h3>
Classe super basilare, attualmente contiene un unico metodo che permette la lettura dello stato di un input da tastiera.
<h3>MouseManager</h3>
Classe per la gestione degli input da mouse, permette di: leggere la posizione del mouse (restituita come Point), leggere lo stato dei pulsanti del mouse, controllare se il puntatore del mouse è all'interno di un GameObject o in un Rect e leggere lo stato della rondella del mouse.
<h3>WindowManager</h3>
Classe per il controllo degli eventi sulla finestra (chiusura, minimizzazione, etc.) in particolare la classe permette l'update degli eventi (effettuato automaticamente se si utilizza GameMain), il controllo di eventi di uscita e il controllo di eventuali eventi di altri tipi (leggere la documentazione sugli <a href="https://wiki.libsdl.org/SDL_EventType">eventi SDL</a>)
<h2>Classi GameObjects</h2>
Le classi GameObjects sono necessarie per l'implementazione di videogiochi in particolare si avranno GameObject come classe padre e due classi figlie PhysicsObject e TextObjet
<h3>GameObject</h3>
La classe GameObject è il tipo base di oggetto necessario per l'utilizzo della libreria in particolare questo comprenderà ogni operazione necessaria in particolare si avranno operazioni per il movimento dell'oggetto (traslazione, rotazione e flipping), per l'mplementazione grafica (texture e animazione) vista la complessità e l'importanza di questa classe si invita ancora una volta a consultare la <a href="http://dispenser.rf.gd/GMKL-Doc/classGameObject.html">documentazione</a> senza dare ulteriori informazioni sulle funzioni da questa implementata.
<h3>PhysicsObject</h3>
Rispetto a GameObject aggiunge un attribito per la massa.
Classe derivata da GameObjects aggiunge in più la gestione basilare della fisica degli oggetti tramite funzioni per applicare forze (considerando il corpo come puntiforme o non) e tracciare eventuali collisioni tra corpi fisici.
<h3>TextObject</h3>
Classe derivata da GameObject aggiunge testo all'oggetto e implementa funzioni per la sua modifica (testo, colore e font) nella gestione grafica verrà considerata anche la texture del testo.
<h2>Classi GraphicsManager</h2>
<h3>Graphics</h3>
La classe Graphics permette la gestione di tutta la grafica dalla creazione della finestra alla rappresentazione dei singoli oggetti al suo interno analogamente a GameObject si invita a consultare la <a href="http://dispenser.rf.gd/GMKL-Doc/classGraphics.html">documentazione</a> vista l'importanza di questa classe.
In particolare la classe implemtenta metodi per la creazione di finestre, la gestione della rappresentazione di oggetti (compresa l'impostazione delle texture), rettangoli e punti e il colore dai vari elementi della finestra (figure basilari e background, NO texture).

/** \mainpage GMKL (versione 0.1.2)
 * La libreria GMKL (Game Maker Library) per il momento è solamente un idea, ma sto comunque lavorando abbastanza seriamente per farla diventare realtà.
 * Si basa sun un insieme di funzioni abbastanza basilari che possono essere necessarie nella creazione di videogiochi (principalmente 2D) o software similari,
 * l'intera libreria per il momento si basa su <a href="https://www.libsdl.org/">SDL2</a>.
 * Nonostante tutte le funzionalità sono abbastanza basilari spero che sia uno strumento utile per velocizzare e semplificare le funzionalità indispensabili
 * nello sviluppo di videogiochi.
 */

#include "GameManager/KeyboardManager.h"

#ifdef GAME_MAIN
#include "GameManager/GameMain.h"
#endif

#include "GameManager/MouseManager.h"
#include "GameManager/WindowManager.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/PhysicsObject/PhysicsObject.h"
#include "GameObjects/TextObject/TextObject.h"
#include "GraphicsManager/Graphics.h"
#include "Types.h"
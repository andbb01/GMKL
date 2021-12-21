/** \mainpage GMKL (versione 0.1.2)
 * La libreria GMKL (Game Maker Library) per il momento è solamente un idea, ma sto comunque lavorando abbastanza seriamente per farla diventare realtà.
 * Si basa sun un insieme di funzioni abbastanza basilari che possono essere necessarie nella creazione di videogiochi (principalmente 2D) o software similari,
 * l'intera libreria per il momento si basa su <a href="https://www.libsdl.org/">SDL2</a>.
 * Nonostante tutte le funzionalità sono abbastanza basilari spero che sia uno strumento utile per velocizzare e semplificare le funzionalità indispensabili
 * nello sviluppo di videogiochi.
 */

#ifndef KM_CNTR
#include "GameManager/KeyboardManager.h"
#endif
#define KM_CNTR

#ifdef GAME_MAIN

#ifndef G_CNTR
#include "GameManager/GameMain.h"
#endif
#define G_CNTR

#endif

#ifndef MMEN_CNTR
#include "GameManager/MouseManager.h"
#endif
#define MMEN_CNTR

#ifndef W_CNTR
#include "GameManager/WindowManager.h"
#endif
#define W_CNTR

#ifndef A_CNTR
#include "GameManager/AudioManager.h"
#endif
#define A_CNTR

#ifndef GO_CNTR
#include "GameObjects/GameObject.h"
#endif
#define GO_CNTR

#ifndef PO_CNTR
#include "GameObjects/PhysicsObject/PhysicsObject.h"
#endif
#define PO_CNTR

#ifndef TO_CNTR
#include "GameObjects/TextObject/TextObject.h"
#endif
#define TO_CNTR

#ifndef GR_CNTR
#include "GraphicsManager/Graphics.h"
#endif
#define GR_CNTR

#ifndef T_CNTR
#include "Types.h"
#endif
#define T_CNTR
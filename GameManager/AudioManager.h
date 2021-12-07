#include "../Types.h"

#ifndef AUDIO_CNTR


/**
 * Classe per la gestione dell'audio tutti i metodi sono statici ed accessibili direttamente senza istanziare la classe
 */
class AudioManager{
    public:
        /**
         * Apre il canale audio per premettere la riproduzione di musica ed effetti
         */
        static void audioStart(){
            Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 512);
        }

        /**
         * Riproduce un effetto audio (estensione wav)
         */
        static void playEffect(std::string filename){
            Mix_Chunk *eff;

            eff = Mix_LoadWAV(filename.c_str());

            Mix_PlayChannel(-1, eff, 0);
        }

        /**
         * Avvia la riproduzione di un file audio e lo riproduce ciclicamente
         */
        static void playMusic(std::string filename){
            Mix_Music *music;

            music = Mix_LoadMUS(filename.c_str());

            Mix_PlayMusic(music, -1);
        }
        /**
         * Imposta il volume degli effetti audio alla percentuale perc
         */
        static void setEffectsVolume(double perc){
            perc = (perc > 1) ? 1 : perc;
            Mix_Volume(-1,MIX_MAX_VOLUME*perc);
        }
        /**
         * Imposta il volume della musica alla percentuale perc
         */
        static void setMusicVolume(double perc){
            perc = (perc > 1) ? 1 : perc;
            Mix_VolumeMusic(MIX_MAX_VOLUME*perc);
        }

        /**
         * Imposta la percentuale di tutto l'audio a perc
         */
        static void setVolume(double perc){
            perc = (perc > 1) ? 1 : perc;
            AudioManager::setEffectsVolume(perc);
            AudioManager::setMusicVolume(perc);
        }
        /**
         * Interrompe la riproduzione della musica sul canale audio
         */
        static void stopMusic(){
            Mix_HaltMusic();
        }
};

#endif

#define AUDIO_CNTR
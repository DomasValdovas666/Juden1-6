#ifndef PLAYER_H
#define PLAYER_H

namespace game{
    namespace content {
        class Player{
        public:
            Player();
            ~Player();
            void update();
            void equip();
        private:
            int health;
            bool allive;
        protected:
            int iq;
        };
    }
}

#endif // PLAYER_H

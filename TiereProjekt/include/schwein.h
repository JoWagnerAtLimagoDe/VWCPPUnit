#pragma once
#include <string>

namespace tiere {
    class schwein
    {
        private:
            std::string name;
            int gewicht;

        public:
            schwein(std::string name = "nobody");
            void fressen();
            void setName(std::string &name);
            std::string getName() const;
            int getGewicht() const;
    };
}

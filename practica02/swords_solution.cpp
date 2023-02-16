#include <iostream>
#include <string>

using namespace std;

class minecraft_swords {
    private:
        int damage;
        int count_kills = 0;
        string name;
        string* mobs = nullptr;

    public:
        int durability;

        // Constructor de nuestra espada
        minecraft_swords(int type, string sword_name){
            // Asignamos nombre a la espada
            this->name = sword_name;

            // Definimos el tipo de espada
            switch (type)
            {
            case 1:
                this->damage = 4;
                this->durability = 59;
                break;
            
            case 2:
                this->damage = 6;
                this->durability = 250;
                break;

            case 3:
                this->damage = 7;
                this->durability = 1561;
                break;
            }

            // Creamos el arreglo de mobs
            mobs = new string[100];

        }

        // Destructor de nuestra espada
        ~minecraft_swords(){
            delete [] mobs;
        }

        // Muestra el numero de mobs con los que ha acabado
        int kills(){
            cout << name << " ha acabado con " << count_kills << " enemigos.\n";
            return count_kills;
        }

        // Muestra la durabilidad de la espada
        int life(){
            cout << name << " le queda " << durability << " puntos de durabilidad.\n";
            return durability;
        }

        // Muestra en cuantos golpes acaba con un enemigo si puede, si no, muestra mensaje que no ha podido
        void hits(string enemy, int enemy_life){
            int count_hits = enemy_life / damage;
            if(enemy_life % damage != 0)
                count_hits++;
            
            if(count_hits > durability){
                cout << name << " no pudo acabar con el " << enemy << " porque se ha roto.\n";
                return;
            }

            durability -= count_hits;
            cout << name << " acabo con el " << enemy << " en " << count_hits << " golpes.\n";
            mobs[count_kills] = enemy;
            count_kills++;
            return;
        }

        // Muestra la lista de enemigos que ha acabado
        void history(){
            cout << name << " ha acabado con los siguientes enemigos: ";
            for(int i = 0; i < count_kills; i++)
                cout << mobs[i] << " ";
            cout << '\n';
            return;
        }
};

int main(){

    

    int type, N;
    string name;

    cin >> type >> name >> N;
    minecraft_swords Espadachin(1, "Espadachin");

    char q;
    // K -> Muestra el numero de kills
    // D -> Muestra la durabilidad de la espada
    // H -> Seguido de `enemy` y `enemy_life` presenta el numero de golpes 
    //      requeridos para acabar con un enemigo en caso de poder
    // Y -> Presenta la lista de enemigos con los que ha acabado
    while(N--){
        cin >> q;

        switch (q)
        {
        case 'K':{
            Espadachin.kills();
            break;
        }

        case 'D':{
            Espadachin.life();
            break;
        }
    
        case 'H':{
            string enemy;
            int enemy_life;
            cin >> enemy >> enemy_life;
            Espadachin.hits(enemy, enemy_life);
            break;
        }
            
        case 'Y':{
            Espadachin.history();
            break;
        }
            
        }
    }
    return 0;
}
//using namespace std;


int main(){
    srand (time(NULL));


string intro_string = R"(
                        .-')        .-') _    ('-.    .-. .-')     ('-.
    .-.        .-.     ( OO ).     ( OO ) )  ( OO ).-.\  ( OO )  _(  OO)    .-.        .-.
 .-,| |,-.  .-,| |,-. (_)---\_),--./ ,--,'   / . --. /,--. ,--. (,------..-,| |,-.  .-,| |,-.
 _\ ' ' /_  _\ ' ' /_ /    _ | |   \ |  |\   | \-.  \ |  .'   /  |  .---'_\ ' ' /_  _\ ' ' /_
(__     __)(__     __)\  :` `. |    \|  | ).-'-'  |  ||      /,  |  |   (__     __)(__     __)
  / . . \    / . . \   '..`''.)|  .     |/  \| |_.'  ||     ' _)(|  '--.  / . . \    / . . \
 `-'| |`-'  `-'| |`-' .-._)   \|  |\    |    |  .-.  ||  .   \   |  .--' `-'| |`-'  `-'| |`-'
    `-'        `-'    \       /|  | \   |    |  | |  ||  |\   \  |  `---.   `-'        `-'
                       `-----' `--'  `--'    `--' `--'`--' '--'  `------'
                            __..._
                        ..-'      o.
                     .-'            :
                 _..'             .'__..--<
          ...--""                 '-.
      ..-"                       __.'
    .'                  ___...--'
   :        ____....---'
  :       .'
 :       :           _____
 :      :    _..--"""     """--..__
:       :  ."                      ""i--.
:       '.:                         :    '.
:         '--...___i---""""--..___.'      :
 :                 ""---...---""          :
  '.                                     :
    '-.                                 :
       '--...                         .'
         :   ""---....._____.....---""
         '.    '.
           '-..  '.
               '.  :
                : .'
               /  :
             .'   :
           .' .--'
          '--'

 _____      _              _                         _       _
|  ___|    | |            | |                       | |     (_)
| |__ _ __ | |_ ___ _ __  | |__   ___   __ _ _ __ __| |  ___ _ _______
|  __| '_ \| __/ _ \ '__| | '_ \ / _ \ / _` | '__/ _` | / __| |_  / _ \
| |__| | | | ||  __/ |    | |_) | (_) | (_| | | | (_| | \__ \ |/ /  __/
\____/_| |_|\__\___|_|    |_.__/ \___/ \__,_|_|  \__,_| |___/_/___\___|
█▄▄ █▀▀ ▀█▀ █░█░█ █▀▀ █▀▀ █▄░█   ▀█ █▀█   ▄▀█ █▄░█ █▀▄   █▀ █▀█
█▄█ ██▄ ░█░ ▀▄▀▄▀ ██▄ ██▄ █░▀█   █▄ █▄█   █▀█ █░▀█ █▄▀   ▄█ █▄█
Eat the #, avoid the X!
)";

std::cout << intro_string;
int board_size;

std::cin >> board_size;

    while(std::cin.fail() || board_size < 20 || board_size > 50){
    std::cin.clear(); // clear bad choice
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
    std::cin.ignore(); // skip bad input
    std::cout << "Wrong input, try again!" << std::endl;
    std::cin >> board_size;
    }

    initscr();      // This initialises the ncurses screen and allocates memory
    refresh();      // Refresh screen to show change
    World game(board_size); //initialises the world starts game based on users board size
    endwin();     //This ends ncurses

    return 0;
}
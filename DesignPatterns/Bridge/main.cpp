#include "player.h"
#include "player_sheet.h"

Dwarf* dwarf = new Dwarf();
Elf* elf = new Elf();
Gnome* gnome = new Gnome();

Warrior* warrior = new Warrior();
Wizard* wizard = new Wizard();
Rogue* rogue = new Rogue();
Monk* monk = new Monk();

int main() {
  Player player1(dwarf, warrior, "Girkar");
  PrintPlayerSheet(player1);

  Player player2(elf, rogue, "Kembley");
  PrintPlayerSheet(player2);
  
  Player player3(gnome, wizard, "Glyrddan");
  PrintPlayerSheet(player3);

  Player player4(gnome, warrior, "Winesa");
  PrintPlayerSheet(player4);

  Player player5(dwarf, monk, "Skirrak");
  PrintPlayerSheet(player5);
}

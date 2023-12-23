#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <unistd.h>
  using namespace std;
     int
       playerHealth = 100, playerCoins = 50, playerExp;
     int
       playerArea = 1;
     int
       playerKnight,
       playerArcher,
       playerMage,
       playerClass;
     int
       StatNeededKnight = 50;
     int
       StatNeededArcher = 50;
     int
       StatNeededMage = 50;
     int
       armorpoints;
     string
       purchase = "";
     int
       healthpotions;
     string
       areaBossHold,
       areaThemeHold;		// used as text generator in hunt and boss
vector < string > areaMobsHold;
//global variables to be used in any function
     void
     createNewArea ()
{
  srand (time (NULL));
  int chooseArea = rand () % 5 + 1;
  int areaHold;
  string mobHold;
  string areaTheme[] =
    { "Woodlands", "Under the Sea", "Mountains", "Caves", "Desert" };
  string areaMobs[] =
    { "Elf", "Druid", "Shaman", "Kraken", "Pirate", "Mermaid", "Roc",
"Scavenger", "Rogue", "Gorgon", "Caveman", "Basilisk", "Mummy", "Bandit",
"Giant Scorpion" };
  string areaBosses[] = { "Treant", "Triton", "Dragon", "Medusa", "Pharoah" };
  areaBossHold = areaBosses[chooseArea];
  areaThemeHold = areaTheme[chooseArea];
  for (int intC = 0; intC < 3; intC++)
    {
      areaHold = (chooseArea * 3) - intC - 1;
      mobHold = areaMobs[areaHold];
      areaMobsHold.push_back (mobHold);
    }				//puts the area mobs within a vector
}

void
runTutorial ()
{
  int trainedAmt;
  int powTrain;
  string userInput;
  bool nextString = false;
  srand (time (NULL));
  cout << "The goal of this game is to clear all 5 areas and their bosses." <<
    endl;
  cout <<
    "(A menu of commands will always be available after the tutorial as well)."
    << endl;
  sleep (1);
  cout << "To start, type ''train'' to select a class to train" << endl;
  while (nextString == false)
    {
      cin >> userInput;
      if (userInput == "train")
	{
	  cout <<
	    "What class do you want to train? (knight/melee, archer/distance, mage/magic) "
	    << endl;
	  string whichClass = "";
	  cin >> whichClass;
	  if (playerCoins > 5)
	    {
	      if (whichClass == "Mage" || whichClass == "mage"
		  || whichClass == "magic")
		{
		  playerCoins = playerCoins - 5 * playerArea;
		  trainedAmt = (rand () % 10 + 1) * playerArea;
		  StatNeededMage -= trainedAmt;
		  cout << "You spent " << 5 *
		    playerArea << "coins, and gained " << trainedAmt <<
		    " magic experience." << endl;
		  nextString = true;	//moves tutorial onto the hunt command
		}
	      else if (whichClass == "Knight" || whichClass == "knight"
		       || whichClass == "melee")
		{
		  playerCoins = playerCoins - 5 * playerArea;
		  trainedAmt = (rand () % 10 + 1) * playerArea;
		  StatNeededKnight -= trainedAmt;
		  cout << "You spent " << 5 *
		    playerArea << " coins, and gained " << trainedAmt <<
		    " melee experience." << endl;
		  nextString = true;
		}
	      else if (whichClass == "Archer" || whichClass == "archer"
		       || whichClass == "distance")
		{
		  playerCoins = playerCoins - 5 * playerArea;
		  trainedAmt = (rand () % 10 + 1) * playerArea;
		  StatNeededArcher -= trainedAmt;
		  cout << "You spent " << 5 *
		    playerArea << " coins, and gained " << trainedAmt <<
		    " distance experience." << endl;
		  nextString = true;
		}
	      else
		{
		  cout << "Not Valid Response." << endl;
		}
	    }
	}
      else
	{
	  cout << "You didn't type the correct word, try again" << endl;
	}
    }
  cout << "" << endl;
  cout <<
    "Training costs gold, so you will have to hunt occasionally to earn gold."
    << endl;
  cout << "Type ''hunt'' to go hunting in the current area." << endl;
  nextString = false;
  while (nextString == false)
    {
      cin >> userInput;
      if (userInput == "hunt")
	{
	  int randString = rand () % 2 + 1;
	  int randMob = rand () % 3;
	  string mobHunt = areaMobsHold[randMob];
	  int goldGenerator = rand () % 5 + 3 * playerArea;	//3-8 coins * player area
	  int mobDmg = rand () % 3 + 4 * playerArea;	//4-7 dmg * player area
	  int hpLoss = mobDmg - armorpoints;
	  if (hpLoss < 0)
	    {
	      hpLoss = 0;	//hp loss cant be negative
	    }
	  playerHealth = playerHealth - hpLoss;
	  playerCoins = playerCoins + goldGenerator;
	  if (randString == 1)
	    {
	      cout << "While hunting, you found a " << mobHunt <<
		". You killed it and received " << goldGenerator <<
		" coins. You took " << hpLoss << " points of damage." << endl;
	    }
	  else if (randString == 2)
	    {
	      cout << "You went hunting and found a " << mobHunt << ". +" <<
		goldGenerator << "coins, -" << hpLoss << "hp." << endl;
	    }
	  nextString = true;
	}
      else
	{
	  cout << "You didn't type the correct word, try again" << endl;
	}
    }
  cout << "You can type shop to purchase armor points or health potions." <<
    endl;
  cout << "Health potions give you 50 health points each." << endl;
  sleep (1);
  cout << ">>>" << endl;
  cout <<
    "Those are the basic commands. Once you think that you are ready to do the area boss fight, type ''boss''"
    << endl;
  cout << "Enjoy!" << endl;
}

void
runTrainClass ()
{
  int trainedAmt;
  int powTrain;			//part of calculating the exp needed for next stat
  srand (time (NULL));
  cout <<
    "What class do you want to train? (knight/melee, archer/distance, mage/magic) "
    << endl;
  string whichClass = "";
  cin >> whichClass;
  if (playerCoins > 5)
    {
      if (whichClass == "Mage" || whichClass == "mage"
	  || whichClass == "magic")
	{
	  playerCoins = playerCoins - 5 * playerArea;
	  trainedAmt = (rand () % 10 + 1) * playerArea;
	  StatNeededMage -= trainedAmt;
	  if (StatNeededMage <= 0)
	    {
	      playerMage += 1;
	      for (int intC = 0; intC < playerMage; intC++)
		{
		  powTrain = pow (25, 1.1);
		}
	      StatNeededMage += 25 + powTrain;
	      cout << "Your magic (Mage) leveled up. It is now level" <<
		playerMage << "!" << endl;
	    }
	  cout << "You spent " << 5 *
	    playerArea << "coins, and gained " << trainedAmt <<
	    " magic experience." << endl;
	}
      else if (whichClass == "Knight" || whichClass == "knight"
	       || whichClass == "melee")
	{
	  playerCoins = playerCoins - 5 * playerArea;
	  trainedAmt = (rand () % 10 + 1) * playerArea;
	  StatNeededKnight -= trainedAmt;
	  if (StatNeededKnight <= 0)
	    {
	      playerKnight += 1;
	      for (int intC = 0; intC < playerKnight; intC++)
		{
		  powTrain = pow (25, 1.1);
		}
	      StatNeededKnight += 25 + powTrain;
	      cout << "Your melee (Knight) leveled up. It is now level " <<
		playerKnight << "!" << endl;
	    }
	  cout << "You spent " << 5 *
	    playerArea << " coins, and gained " << trainedAmt <<
	    " melee experience." << endl;
	}
      else if (whichClass == "Archer" || whichClass == "archer"
	       || whichClass == "distance")
	{
	  playerCoins = playerCoins - 5 * playerArea;
	  trainedAmt = (rand () % 10 + 1) * playerArea;
	  StatNeededArcher -= trainedAmt;
	  if (StatNeededArcher <= 0)
	    {
	      playerArcher += 1;
	      for (int intC = 0; intC < playerArcher; intC++)
		{
		  powTrain = pow (25, 1.1);
		}
	      StatNeededArcher += 25 + powTrain;
	      cout << "Your distance (Archer) leveled up. It is now level " <<
		playerArcher << "!" << endl;
	    }
	  cout << "You spent " << 5 *
	    playerArea << " coins, and gained " << trainedAmt <<
	    " distance experience." << endl;
	}
      else
	{
	  cout << "Not Valid Response." << endl;
	}
    }
  else
    {
      cout <<
	"You do not have enough coins. Use the Hunt command to gather some."
	<< endl;
    }
}

void
runOpenShop ()
{
  int temp;
  cout << "What would you like to buy? Enter corresponding number " << endl;
  cout << "1) 1 armor point - 15 coins" << endl;
  cout << "2) 5 armor points - 70 coins" << endl;
  cout << "3) 15 armor points - 200 coins" << endl;
  cout << "4) Health Potion - 5 coins for each one" << endl;
  cout << "5) Exit" << endl;
  cin >> purchase;
  if (purchase == "1" && playerCoins > 15)
    {
      playerCoins -= 15;
      cout << "You have purchased 1 armor point." << endl;
      armorpoints += 1;
    }
  else if (purchase == "2" && playerCoins > 70)
    {
      playerCoins -= 70;
      cout << "You have purchased 5 armor points." << endl;
      armorpoints += 5;
    }
  else if (purchase == "3" && playerCoins > 200)
    {
      playerCoins -= 200;
      cout << "You have purchased 15 armor points." << endl;
      armorpoints += 15;
    }
  else if (purchase == "4")
    {
      cout << "How much would you like to buy? " << endl;
      cin >> temp;
      if (playerCoins > temp * 5)
	{
	  cout << "You have purchased " << temp << " health potions." << endl;
	  healthpotions += temp;
	}
      else
	{
	  cout <<
	    "Please enter a valid amount and makesure you have enough coins."
	    << endl;
	}
    }
  else if (purchase == "5")
    {
      cout <<
	"Thank you for checking out our shop. Hopefully next time you purchase something."
	<< endl;
    }
  else
    {
      cout <<
	"Please enter a valid number and/or make sure you have enough coins."
	<< endl;
    }
}

void
runHunt ()
{
  srand (time (NULL));
  int randString = rand () % 2 + 1;
  int randMob = rand () % 3;
  string mobHunt = areaMobsHold[randMob];
  int goldGenerator = rand () % 5 + 3 * playerArea;	//3-8 coins * player area
  int mobDmg = rand () % 3 + 4 * playerArea;	//4-7 dmg * player area
  int hpLoss = mobDmg - armorpoints;
  if (playerHealth > 0)
    {
      if (hpLoss < 0)
	{
	  hpLoss = 0;		//hp loss cant be negative
	}
      playerHealth = playerHealth - hpLoss;
      if (playerHealth > 0)
	{
	  playerCoins = playerCoins + goldGenerator;
	  if (randString == 1)
	    {
	      cout << "While hunting, you found a " << mobHunt <<
		". You killed it and received " << goldGenerator <<
		" coins. You took " << hpLoss << " points of damage." << endl;
	    }
	  else if (randString == 2)
	    {
	      cout << "You went hunting and found a " << mobHunt << ". +" <<
		goldGenerator << "coins, -" << hpLoss << "hp." << endl;
	    }
	}
      else
	{
	  cout <<
	    "You were about to die, luckily a nomad saw you and saved you. Please buy and use a health potion."
	    << endl;
	  playerHealth = 0;
	  runOpenShop ();
	}
    }
  else if (playerHealth <= 0 && healthpotions == 0 && playerCoins == 0)
    {
      cout <<
	"You have died. You have been ressurected, and your health has been restored, however you have lost 100 experience from each stat."
	<< endl;
      StatNeededArcher += 100;
      StatNeededKnight += 100;
      StatNeededMage += 100;
      playerHealth = 100;
    }
  else
    {
      cout <<
	"Make sure you have enough health. If you do not have enough health, please heal up by purchasing a health potion from the shop and using the heal command"
	<< endl;
    }
}

void
runPlayerProfile ()
{
  cout << "_____________________" << endl;
  cout << "| Player Health: " << playerHealth << "|" << endl;
  cout << "| Player Armor: " << armorpoints << "|" << endl;
  cout << "| Player Area: " << playerArea << "|" << endl;
  cout << "| Player Magic: " << playerMage << "|" << endl;
  cout << "| Player Melee: " << playerKnight << "|" << endl;
  cout << "| Player Distance:" << playerArcher << "|" << endl;
  cout << "| Player Coins:" << playerCoins << "|" << endl;
  cout << "|____________________|" << endl;
}

void
runHeal ()
{
  int amtHealed;
  if (playerHealth < 100 && healthpotions > 0)
    {
      healthpotions -= 1;
      amtHealed = 100 - playerHealth;
      playerHealth += 50;
      if (playerHealth > 100)
	{
	  playerHealth = 100;
	  cout << "You used one health potion, and you are now at 100 health."
	    << "You healed " << amtHealed << "." << endl;
	}
      else
	{
	  cout << "You have healed 50 health and now you have " <<
	    playerHealth << " health" << endl;
	}
    }
  else
    {
      cout <<
	"You either already have full health or you don't have any health potions!!"
	<< endl;
    }
}

void
runBoss ()
{
  srand (time (NULL));
  int BossHealth = 100 * playerArea;
  string BossName = areaBossHold;
  if (playerArcher >= 2 * playerArea || playerKnight >= 2 * playerArea
      || playerMage >= 2 * playerArea)
    {
      string whichClass = "";
      cout << "You must defeat " << BossName << " to move onto the next area!"
	<< endl;
      while (BossHealth > 0 && playerHealth > 0 && healthpotions > 0)
	{
	  cout << "What stat do you want to attack the boss with? " << endl;
	  cin >> whichClass;
	  if (whichClass == "Mage" || whichClass == "mage"
	      || whichClass == "magic")
	    {
	      int playerDamage = rand () % 5 * playerMage * 2;
	      int BossDmg = rand () % 3 + 8 * playerArea;
	      int hpLoss = BossDmg - armorpoints;
	      if (hpLoss < 0)
		{
		  hpLoss = 0;	//hp loss cant be negative
		}
	      playerHealth = playerHealth - hpLoss;
	      BossHealth -= playerDamage;
	      cout << "You did " << playerDamage <<
		" damage. The boss now has " << BossHealth << " health left."
		<< endl;
	      cout << "The boss did " << hpLoss << " damage. You now have " <<
		playerHealth << " health left." << endl;
	    }
	  else if (whichClass == "Knight" || whichClass == "knight"
		   || whichClass == "melee")
	    {
	      int playerDamage = rand () % 5 * playerKnight * 2;
	      int BossDmg = rand () % 3 + 8 * playerArea;
	      int hpLoss = BossDmg - armorpoints;
	      playerHealth = playerHealth - hpLoss;
	      BossHealth -= playerDamage;
	      cout << "You did " << playerDamage <<
		" damage. The boss now has " << BossHealth << " health left."
		<< endl;
	      cout << "The boss did " << BossDmg << " damage. You now have "
		<< playerHealth << " health left." << endl;
	    }
	  else if (whichClass == "Archer" || whichClass == "archer"
		   || whichClass == "distance")
	    {
	      int playerDamage = rand () % 5 * playerArcher * 2;
	      int BossDmg = rand () % 3 + 8 * playerArea;
	      int hpLoss = BossDmg - armorpoints;
	      playerHealth = playerHealth - hpLoss;
	      BossHealth -= playerDamage;
	      cout << "You did " << playerDamage <<
		" damage. The boss now has " << BossHealth << " health left."
		<< endl;
	      cout << "The boss did " << BossDmg << " damage. You now have "
		<< playerHealth << " health left." << endl;
	    }
	  else
	    {
	      cout <<
		"Please select a appropriate response. Options are: Mage, Knight, or Archer."
		<< endl;
	    }
	}
      if (BossHealth <= 0)
	{
	  cout <<
	    "Congratulations! You have defeated the boss and advanced a level."
	    << endl;
	  playerArea + 1;
	  createNewArea ();
	}
      else if (playerHealth <= 0)
	{
	  cout <<
	    "You have died in your attempt to defeat the boss. Luckily, a healer spotted you and healed you with a potion. Please come back and retry with more armor or stats."
	    << endl;
	  healthpotions -= 1;
	  playerHealth += 100;
	}
    }
  else
    {
      cout <<
	"You need stats that are at least 2x your area to attempt. To guarantee a win, you should try with 5x. If you have enough stats, please make sure you have at least 1 health potion in your inventory to start."
	<< endl;
    }
}

int
main ()
{
  string userAction;
  string userIn;
  createNewArea ();		//generates the area theme
  cout <<
    "Hello Player! Would you like a tutorial before you begin playing?(y/n)"
    << endl;
  cin >> userIn;
  if (userIn == "yes" || userIn == "y")
    {
      runTutorial ();
    }
  else
    {
      cout << "Let's Start!" << endl;
    }
  while (userAction != "quit" && playerArea < 6)
    {
      cin >> userAction;
      if (userAction == "train")
	{			//more class stat, less exp
	  runTrainClass ();
	}
      else if (userAction == "shop")
	{
	  runOpenShop ();
	}
      else if (userAction == "hunt")
	{			//more exp, less class stat
	  runHunt ();
	}
      else if (userAction == "profile")
	{
	  runPlayerProfile ();
	}
      else if (userAction == "heal")
	{
	  runHeal ();
	}
      else if (userAction == "boss")
	{
	  runBoss ();
	}
      else
	{
	  cout <<
	    "Not a valid option. Options are: profile, train, hunt, heal, shop and boss."
	    << endl;
	}
    }
  if (playerArea == 6)
    {
      cout << "You cleared all the areas and beat the game!" << endl;
    }
  cout << "Thanks for playing!";
  return 0;
}

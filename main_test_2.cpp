#include "goban.h"
#include <gtest>

TEST(ObjectTest, TestInitialisation) {
	goban *myGoban = new goban(10);
	EXPECT_EQ(myGoban->getTaille(), 10);
	EXPECT_EQ(myGoban->getJoueur(), 0);
	EXPECT_EQ(myGoban->getCapture1(), 0);
	EXPECT_EQ(myGoban->getCapture2(), 0);
}

TEST (TestCréationFichier, TestEcritureInit){
    goban * myGoban = new goban(10);
    myGoban->ecriture();
    EXPECT_EQ(myGoban->lecture(),true);
}

TEST (TestJouer,JoueursPosentPion){
    goban * myGoban = new goban(10);
    myGoban->setJoueur(0);
    myGoban->jouer(2,3);
    EXPECT_EQ(myGoban->getCase(2,3),0);
    EXPECT_EQ(myGoban->getJoueur(),1);
    myGoban->jouer(5,8);
    EXPECT_EQ(myGoban->getCase(5,8),1);
    EXPECT_EQ(myGoban->getJoueur(),0);
}

TEST (TestJouer,CaseOccupée){
    goban * myGoban = new goban(10);
    myGoban->setJoueur(0);
    myGoban->jouer(2,3);
    myGoban->jouer(2,3);
    EXPECT_EQ(myGoban->getCase(2,3),0);
    EXPECT_EQ(myGoban->getJoueur(),1);
}

TEST (TestJouer,SupprimerGroupe){
    goban * myGoban = new goban(10);
    myGoban->setJoueur(1);
    myGoban->jouer(1,1);
    myGoban->setJoueur(0);
    myGoban->jouer(1,0);
    myGoban->setJoueur(0);
    myGoban->jouer(2,1);
    myGoban->setJoueur(0);
    myGoban->jouer(1,2);
    myGoban->setJoueur(0);
    myGoban->jouer(0,1);
    EXPECT_EQ(myGoban->getCase(1,1),-1);
}

TEST (TestJouer,HorsPlateau){
    goban * myGoban = new goban(10);
    myGoban->jouer(11,0);
    for (int i=0;i<myGoban->getTaille();i++){
        for (int j=0;j<myGoban->getTaille();j++))
        {
            EXPECT_EQ(myGoban->getCase(i,j),-1);
        }
    }
}

TEST (TestJouer,TestSuicide){
    goban * myGoban = new goban(10);
    myGoban->jouer(1,0);
    myGoban->setJoueur(0);
    myGoban->jouer(2,1);
    myGoban->setJoueur(0);
    myGoban->jouer(1,2);
    myGoban->setJoueur(0);
    myGoban->jouer(0,1);
    myGoban->jouer(1,1);
    EXPECT_EQ(myGoban->getCase(1,1),-1);
    EXPECT_EQ(myGoban->getJoueur(),1);
}














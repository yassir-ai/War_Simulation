/**  @file     soldat.hpp                                                                                                                                
 * @author     Yassir, Achraf, Xuanzhe                                                                                                        
 * @version    1.0.0.1                                                
 * @date       2023.01.31                                                                                
 * @copyright  Copyright (c)
 *****************************************************************
 * @attention
 * Development environment: Windows
 * @par Modification log:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2023/01/31  <td>1.0      <td>Achraf    <td>Creating the initial version
 * <tr><td>2023/02/10  <td>2.0      <td>Xuanzhe   <td>Solution (Vector n'est pas un modèleC/C++(864))
 * <tr><td>2023/02/20  <td>3.0      <td>Yassir   <td>Problem solving and optimization
 * </table>
 ******************************************************************
 */
#ifndef SOLDAT__HPP
#define SOLDAT__HPP

#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <utility>

using std::cout;
using std::cin;
using std::endl;
using pair = std::pair<int, int>; /**< creates an alias pair for the std::pair<int, int> type. 
it Indicates position information, horizontal and vertical coordinates*/



/**

@brief The Soldat class represents a soldier with attributes like health points, strength, precision, speed, and an ID.
*/
class Soldat
{

protected:

    int hp;                         /**< The soldier's health points. */
    int strength;                    /**< The soldier's attack strength. */
    float precision;                /**< The soldier's shooting precision. */
    int speed;                      /**< The soldier's movement speed. */
    int id;                         /**< The soldier's `ID. */

public:

    Soldat();
    int getHp();
    int getStrength();
    float getPrecision();
    int getSpeed();
    int getId();

    void setHp(int );
    void setStrength(int );
    void setPrecision(float );
    void setSpeed(int );
    void setId(int );

    void incremId(int );

    bool estMort();
    bool est_Ami(Soldat&);

    int decider(); // 0 = tirer, 1 = bouger
    int tirer();
    void reduireHp(int );

    /**
     * @brief After being affected by terrain weather, keep this state to prevent, multiple weather and terrain effects make the attribute stacked
     */
    virtual void restituer() = 0; 

    /**
     * @brief Change Location
     *
     * @param position Initial Location
     * 
     * @return nv_position new Location 
     */
    virtual pair bouger(pair ) = 0;     

  /**
    * @brief Attack Location
    *
    * @param position Own position
    * 
    * @return nv_position Location of the enemy
    */
    virtual pair Position_Tir(pair ) = 0;

    virtual void AfficherSoldat() = 0;

    /**
     * @brief Which type of soldier is returned
     * 
     * @return Soldier Type
     */
    virtual int getType() = 0;
    

    virtual ~Soldat();
};

class Infanterie : public Soldat  //0
{

public:

    static const int type;
    Infanterie();
    void AfficherSoldat() override;
    int getType() override;
    void restituer() override;
    pair bouger(pair ) override;
    pair Position_Tir(pair ) override;
};

class Cavalerie : public Soldat   //1
{

public:

    static const int type;
    Cavalerie();
    void AfficherSoldat() override;
    int getType() override;
    void restituer() override;
    pair bouger(pair ) override;
    pair Position_Tir(pair ) override;
};

class Char : public Soldat     //2
{

public:

    static const int type;
    Char();
    void AfficherSoldat() override;
    int getType() override;
    void restituer() override;
    pair bouger(pair ) override;
    pair Position_Tir(pair ) override;
};

class Force_Aerienne : public Soldat    //3
{

public:

    static const int type;
    Force_Aerienne();
    void AfficherSoldat() override;
    int getType() override;
    void restituer() override;
    pair bouger(pair ) override;
    pair Position_Tir(pair ) override;
};

#endif
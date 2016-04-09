/*
 * definition.h
 *
 *  Created on: Mar 3, 2016
 *      Author: kevinw
 */

#ifndef DEFINITION_H_
#define DEFINITION_H_

#define _DEBUG_
//const int CLEAR_WIN = -1;

enum gamestate {NAVIGATE, COMMAND, SELECT_FREE_SPACE, SELECT_WEAPON, SELECT_ENEMY, MENU};
enum {MOVE, ATTACK, END_TURN, CANCEL, LAST_OPTION=CANCEL};
enum {EXIT = -1, OKAY};
enum {CMD_LIST, MENU_LIST};
enum {M_END_TURN, M_CANCEL, M_LAST_OPTION=M_CANCEL};
#endif /* DEFINITION_H_ */

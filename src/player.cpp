#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


#include "player.hpp"



int
Player::
count = 0;


/*
 * Player: an abstraction over all sorts of all intelligent players whether it's 
 * natural or artifitial
 */

Player::
~Player(){
  // std::cout << "Player Destroyed !!\n";
}



/*
 * HumanPlayer: realies on the user input to play the game
 */

HumanPlayer::
HumanPlayer()
{
  // std::cout << "Human Player Created !!\n";
  m_order = count + 1;
  // std::cout << "order : " << m_order << "\n";
  count++;
}



HumanPlayer::
~HumanPlayer()
{
  // std::cout << "Human Player Destroyed !!\n";
}




GameState
HumanPlayer::
move(State* state){
  // std::cout << "Human Player " << m_order << "  Move\n";
  if(!state->human_act(m_order)){
    std::cerr << "Human player couldn't make a move!!\n";
    exit(EXIT_FAILURE);
  }
  return (state->status() == S_TERMINAL)? S_DONE : S_GOING;
}


/*
 * ComputerPlayer: an abstraction over all Artifitially Intelligent agents that would
 * sorlve any given game
 */

ComputerPlayer::
~ComputerPlayer(){
  // std::cout << "Computer Player Destroyed !!\n";
}




/*
 * RandomPlayer: goes through the action set and picks one at random
 */

RandomPlayer::
RandomPlayer()
{
  // std::cout << "Random Player Created!!\n";
}

RandomPlayer::
~RandomPlayer(){
  // std::cout << "Random Player Destroyed!!\n";
}


GameState
RandomPlayer::
move(State* state){
  std::vector<Action*> act_set = state->action_set(m_order);
  int random_move = 0;
  if(act_set.size() > 1) random_move = get_random_number(act_set.size());
  if(state->act(*act_set[random_move], m_order)){
    std::cerr << "Random Player couldn't act on the state!!\n";
    exit(EXIT_FAILURE);
  }
  GameState result = (state->status() == S_TERMINAL)? S_DONE : S_GOING;
  for(int i = 0; i < act_set.size(); i++) delete act_set[i];
  return result;
}


int
RandomPlayer::
get_random_number(int bound){
  srand(time(NULL));
  return rand() % bound;
}


/*
 * MiniMax player solves the game based on building the decision tree and traversing it
 * to find the next move through MiniMax algorithms
 */

MiniMaxPlayer::
MiniMaxPlayer(){
  // std::cout << "MiniMax Player Created!!\n";
  m_order = count + 1;
  m_depth = -1;
  count++;
}

MiniMaxPlayer::
~MiniMaxPlayer(){
  // std::cout << "MiniMax Player Destroyed!!\n";
}

GameState
MiniMaxPlayer::
move(State* state){
  StateNode root(state , m_order);
  std::vector<Action*> act_set = state->action_set(m_order);
  std::pair<int,int> max_val = {INT_MIN, INT_MAX};
  Action* best_action;
  // std::cout << "outcomes: \n";
  StateNode::count = 0;
  for(int i = 0; i < act_set.size(); i++){
    StateNode child = root;
    child.update(*(act_set[i]), m_order);
    std::pair<int,int> val = eval(child, false, 1);
    child.state()->display();
    std::cout << "(" << val.first << "," << val.second <<  ") \n";
    if(val.first > max_val.first || ((val.first == max_val.first) && (val.second < max_val.second))){ 
      max_val = val;
      best_action = act_set[i];
    }
  }
  std::cout << "\n";
  std::cout << StateNode::count << " states explored"<< std::endl;;
  if(best_action == NULL)
    return S_FAILED;
  if(!state->act(*best_action, m_order)){
    std::cerr << "Minimax Player couldn't make a move!!\n";
    exit(EXIT_FAILURE);
  }
  return (state->status() == S_TERMINAL)? S_DONE : S_GOING;
}

std::pair<int,int>
MiniMaxPlayer::
eval(StateNode root, bool is_maximize, int depth){
  if((m_depth < 0) && root.is_terminal()) return {root.utility(),depth};
  if((m_depth > 0) && (root.is_terminal() || (depth >= m_depth))) return {root.check_huristic(),depth};
  int player = (is_maximize?((m_order == 1)? 1:2 ) : ((m_order == 1)? 2: 1));
  std::vector<Action*> act_set = root.state()->action_set(player);
  std::pair<int,int> max_val = {INT_MIN,INT_MAX};
  std::pair<int,int> min_val = {INT_MAX,INT_MAX};
  Action* best_action;
  for(int i = 0; i< act_set.size(); i++){
    StateNode child = root;
    child.update(*(act_set[i]), m_order);
    std::pair<int,int> val = eval(child, !is_maximize, depth +1);
    // std::cout << "(" << val.first << "," << val.second << ")\n";
    // child.state()->display();
    // char c;
    // std::cin >> c;
    if(is_maximize){
      if(val.first > max_val.first || ((val.first == max_val.first) && (val.second < max_val.second))){
        max_val = val;
      }
    }
    else{
      if(val.first < min_val.first || ((val.first == min_val.first) && (val.second < min_val.second)))
        min_val = val;
    }
  }

  return (is_maximize? max_val: min_val);
}

/* H_MiniMaxPlayer: plays minimax with the huristics to evaluate at a certain state upto a 
 * defined depth
 */

H_MiniMaxPlayer::
H_MiniMaxPlayer(int depth){
  m_depth = depth;
}


H_MiniMaxPlayer::
~H_MiniMaxPlayer(){
}


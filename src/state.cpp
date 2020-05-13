#include "state.hpp"



State::
~State(){
}

int
StateNode::
count = 0;

StateNode::
StateNode( State* state, int player)
  : m_state(state), m_player(player), m_utility(-2), player_move(player)
{
  count++;
}

StateNode::
StateNode( const StateNode& other){
  m_state = other.state()->copy();
  m_player = other.player();
  m_utility = other.utility();
  player_move = other.player_move;
  count++;
}

StateNode::
~StateNode(){
}

bool
StateNode::
update(const Action& a, int p){
  bool res = m_state->act(a, p);
  m_utility = m_state->utility();
  player_move = p;
  return res;
}

#ifndef ACTION_HPP
#define ACTION_HPP

class Action {
  protected:
    int m_player;
  public:
  virtual ~Action();
  int player() const {return m_player;}
  virtual int move() const = 0;
};


#endif /* ACTION_HPP */

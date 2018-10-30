/// John Fahringer
/// OOP Practice
#include "card.hpp"
#include <array>
// Values of a poker hand:
// - High card
// - Two
// - Two pair
// - Three
// - Straight (5 consecutive, ace plays both)
// - Flush (same color)
// - Full House
// - Four
// - Straight Flush

struct High
{
    std::array<Rank, 5> getRanks(){return ranks;}

  private:
    // We need all 5 ranks since two hands might
    // have the same crappy hand.
    //
    // Must be sorted in order of rank.
    std::array<Rank, 5> ranks;
};

bool operator<(High a, High b)
{
  return a.getRanks() < b.getRanks();
}

struct Two
{
    Rank getPair(){return pair;}
    std::array<Rank, 3> getHigh(){return high;}

  private:
    // The rank of the pair.
    Rank pair;

    // The sorted rank of remaining cards.
    std::array<Rank, 3> high;
};

bool operator<(Two a, Two b)
{
  if (a.getPair() < b.getPair())
    return true;
  if (b.getPair() < a.getPair())
    return false;
  if (a.getHigh() < b.getHigh())
    return true;
  else
    return false;
}

struct TwoPair
{
    array<Rank, 2> getPairs(){return pairs;}
    Rank getHigh(){return high};
  private:  
    // The sorted ranks of pairs.
    std::array<Rank, 2> pairs;

    // The remaining high card.
    Rank high;
};

bool operator<(TwoPair a, TwoPair b)
{
  if (a.getPairs() < b.getPairs())
    return true;
  if (b.getPairs() < a.getPairs())
    return false;
  if (a.getHigh() < b.getHigh())
    return true;
  else 
    return false;
}

struct Three
{
    Rank getThree(){return three;}
    std::array<Rank, 2> getHighs() {return high;}
  private: 
    // The rank of the three-of-a-kind.
    Rank three;

    // Sorted high cards for tie breakers.
    std::array<Rank, 2> high;
};

bool operator<(Three a, Three b)
{
  if (a.getThree() < b.getThree())
    return true;
  if (b.getThree() < a.getThree())
    return false;
  if (a.getHighs() < b.getHighs())
    return true;
  else
    return false;
}
struct Straight
{
    Rank getHigh(){return high;}
  private:
    // The rank of the highest card.
    Rank high;
};

bool operator<(Straight a, Straight b)
{
  return a.getHigh() < b.getHigh();
}
struct Flush
{
    array<Rank, 5> getHigh(){return high;}
  private:
    // High card for equal flushes wins.
    std::array<Rank, 5> high;
};

bool operator<(Flush a, Flush b)
{
  return a.getHigh() < b.getHigh();
}
struct FullHouse
{
    std::array<Rank, 2> getHigh(){return high;}
  private:  
    // Two ranks: the pair over the triple.
    std::array<Rank, 2> high;
};

bool operator<(FullHouse a, FullHouse b)
{
  return a.getHigh() < b.getHigh();
}

struct Four
{
    Rank getRank(){return rank;}
    Rank getHigh(){return high;}
  private: 
    Rank rank;

    // NOTE: Not usually needed since you can't
    // have two equal four-of-a-kind values.
    Rank high;
};

bool operator<(Four a, Four b)
{
  if (a.getRank() < b.getRank())
    return true;
  if (a.getRank() < b.getRank())
    return false;
  if (a.getHigh() < b.getHigh())
    return true;
  else 
    return false;
}

struct StraightFlush
{
    Rank getHigh(){return high;}
  private:  
    // Just need the rank of the high card.
    Rank high;
};

bool operator<(StraightFlush a, StraightFlush b)
{
  return a.getHigh() < b.getHigh();
}
// Discriminator for the values of a poker hand.
enum ValueKind
{
  high,
  two_kind,
  two_pair,
  three_kind,
  straight,
  flush,
  full_house,
  four_kind,
  straight_flush,
};

enum ValueData
{
  High high;
  Two two;
  TwoPair twice;
  Three three;
  Straight straight;
  Flush flush;
  FullHouse house;
  Four four;
  StraightFlush sf;
};

/// Finish implementing this and operators
struct Value
{
	Value(ValueKind kind, ValueData data)
		: k(kind), d(data) {}
	ValueKind getKind() { return k; }
	ValueData getData() { return d; }
  
private:
	  ValueKind k;
	  ValueData d;
};

bool operator<(const Value& a, const Value& b)
{
  if (a.getKind() < b.getKind())
    return true;
  if (b.getKind() < a.getKind())
    return false;
  switch (a.getKind()) {
  case high:
    return a.high < b.high;
  case two_kind:
    return a.two_kind < b.two_kind;
  case two_pair:
    return a.two_pair < b.two_pair;
  case three_kind:
    return a.three_kind < b.three_kind;
  case straight:
    return a.straight < b.straight;
  case flush:
    return a.flush < b.flush;
  case full_house:
    return a.full_house < b.full_house;
  case four_kind:
    return a.four_kind < b.four_kind;
  case straight_flush:
    return a.straight_flush < b.straight_flush;
  }
}

#include "promotedCarModelStack.h"
#include <stdexcept>
#include <deque>
#include <iostream>

/*
I the undersigned promise that the submitted assignment is my own work. While I was 
free to discuss ideas with others, the work contained is my own. I recognize that 
should this not be the case; I will be subject to penalties as outlined in the course 
syllabus. 
Name: Maxine Mayor
Red ID: 825551461
*/

/**
   * @brief push operation, pushing the latest promoted model onto the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param model 
   * @param price 
   */
void PromotedCarModelStack::push (string model, int price) {
  PromotedModel currmodel (model, price);	//creates new object
  mydeque.push_front (currmodel); //push latest promoted model to stack
  
  if (mydeque.size () == 1) { //push first model into highLow deque
    highLowDeque.push_back (currmodel);
  }
  if (price > highLowDeque.front ().getPromotedPrice ()) { //push new max to front of highLow deque	
    highLowDeque.push_front (currmodel);	
  }
  if (price < highLowDeque.back ().getPromotedPrice ()) { //push new min to back of highLow deque	
    highLowDeque.push_back (currmodel);	
  } 
}

/**
   * @brief pop operation, popping the latest promoted model off the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param  
   * @return PromotedModel
   */

PromotedModel PromotedCarModelStack::pop () {			
  if (mydeque.empty ()) {
    throw logic_error ("Promoted car model stack is empty");
  }
  
  PromotedModel currmodel = mydeque.front();
  mydeque.pop_front();

  if (currmodel.getPromotedPrice() == highLowDeque.front().getPromotedPrice()) { //if popped off value matches current high price
    highLowDeque.pop_front(); //pop front of secondary deque (highLowDeque)
  }
  
  if (currmodel.getPromotedPrice() == highLowDeque.back().getPromotedPrice()) { //if popped off value matches current low price
    highLowDeque.pop_back(); //pop back of secondary deque (highLowDeque)
  }
    
  return currmodel;
}

/**
   * @brief peek operation, peeking the latest promoted model at the top of the stack (without popping)
            Both time and auxiliary space complexity need to be O(1) 
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::peek () {
  if (mydeque.empty ()) {
    throw logic_error ("Promoted car model stack is empty");
  }
  else {
    return mydeque.front(); //peek top of stack
  }
}

/**
   * @brief getHighestPricedPromotedModel, 
   *        getting the highest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getHighestPricedPromotedModel () {
  if (mydeque.empty ()) {
    throw logic_error ("Promoted car model stack is empty");
  }
  else {
    return highLowDeque.front();	//return highest price
  }
}

/**
   * @brief getLowestPricedPromotedModel, 
   *        getting the lowest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getLowestPricedPromotedModel () {
  if (mydeque.empty ()) {
    throw logic_error ("Promoted car model stack is empty");
  }
  else {
    return highLowDeque.back (); //return lowest price
  }
}

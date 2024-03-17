
#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H


#define SET_BIT(reg,bit) (reg |= (1<<bit))
#define CLEAR_BIT(reg,bit) (reg &= ~(1<<bit))
#define GET_BIT(reg,bit) ((reg & (1<<bit))>>bit)
#define TOGGLE_BIT(reg,bit) (reg ^= (1<<bit))
#endif
#pragma once

#include <stdint.h>

class GamePolicy
{
public:
  bool f_draw_item_shadow;                      /**< Draw shadows from the inventory items. */

  int32_t starting_cash_easy;
  int32_t starting_cash_medium;
  int32_t starting_cash_hard;

  /* Battle */
  bool f_drop_everything;               /**< Enemy drop all equipment. */

  int8_t enemy_weapon_minimal_status;   /**< Minimal status of the enemy weapon (0 - 100). */
};

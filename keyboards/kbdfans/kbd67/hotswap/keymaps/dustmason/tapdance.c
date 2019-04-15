enum td_keycodes {
  LGUI_LBRACE, // tap for {, hold for LGUI
  RGUI_RBRACE  // tap for }, hold for RGUI
};

typedef enum { SINGLE_TAP = 1, SINGLE_HOLD = 2 } td_state_t;

typedef struct {
  bool is_press_action;
  int state;
} tap;

static td_state_t td_state;
int cur_dance (qk_tap_dance_state_t *state);
void gui_lbr_finished (qk_tap_dance_state_t *state, void *user_data);
void gui_lbr_reset (qk_tap_dance_state_t *state, void *user_data);
void gui_rbr_finished (qk_tap_dance_state_t *state, void *user_data);
void gui_rbr_reset (qk_tap_dance_state_t *state, void *user_data);

// TapDance for Command keys: tap for { and }, hold for LGUI/RGUI
// see https://docs.qmk.fm/#/feature_tap_dance?id=example-5-using-tap-dance-for-advanced-mod-tap-and-layer-tap-keys

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
    else { return SINGLE_HOLD; }
  }
  else { return 3; } // any number higher than the maximum state value you return above
}

void gui_lbr_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP: register_code(KC_LSFT); register_code(KC_LBRC); break;
    case SINGLE_HOLD: register_mods(MOD_BIT(KC_LGUI)); break;
  }
}

void gui_lbr_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP: unregister_code(KC_LBRC); unregister_code(KC_LSFT); break;
    case SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LGUI)); break;
  }
}

void gui_rbr_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP: register_code(KC_RSFT); register_code(KC_RBRC); break;
    case SINGLE_HOLD: register_mods(MOD_BIT(KC_RGUI)); break;
  }
}

void gui_rbr_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP: unregister_code(KC_RBRC); unregister_code(KC_RSFT); break;
    case SINGLE_HOLD: unregister_mods(MOD_BIT(KC_RGUI)); break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [LGUI_LBRACE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_lbr_finished, gui_lbr_reset),
  [RGUI_RBRACE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_rbr_finished, gui_rbr_reset)
};

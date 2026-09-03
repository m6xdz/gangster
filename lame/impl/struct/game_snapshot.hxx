#pragma once

#include <impl/struct/osu_types.hxx>
#include <string>
#include <cstdint>

namespace osu {

    struct game_snapshot_t {
        bool attached = false;
        client_kind_t client = client_kind_t::none;
        int32_t pid = 0;
        int32_t cur_time = 0;
        game_state_t cur_state = game_state_t::main_menu;
        int32_t cur_mod_state = 0;
        int32_t map_id = 0;
        int32_t set_id = 0;
        std::string map_folder;
        std::string map_file;
        std::string beatmap_hash;
        std::string beatmap_version;
        uint64_t game_base = 0;
        uint64_t player_screen = 0;
        uint64_t drawable_ruleset = 0;
        std::string client_version;
        std::string offset_version;
        bool offset_mismatch = false;
        std::string songs_path;
        int32_t left_key = 'S';
        int32_t right_key = 'D';
        float speed_mult = 1.f;
        bool is_replay = false;

        // Lazer diagnostics: these are populated by c_osu_lazer::update().
        // They intentionally expose each link in the pointer chain so a broken
        // offset can be identified from the System tab without a debugger.
        bool diag_clock_ok = false;
        bool diag_beatmap_ok = false;
        bool diag_stack_ok = false;
        bool diag_current_screen_ok = false;
        bool diag_submitting_api_match = false;
        bool diag_player_api_match = false;
        bool diag_ruleset_ok = false;
        int32_t diag_stack_count = 0;
        int32_t diag_raw_time = 0;
        uint64_t diag_beatmap_clock = 0;
        uint64_t diag_final_source = 0;
        uint64_t diag_beatmap_bindable = 0;
        uint64_t diag_working_beatmap = 0;
        uint64_t diag_screen_stack = 0;
        uint64_t diag_stack = 0;
        uint64_t diag_current_screen = 0;
        uint64_t diag_base_api = 0;
        uint64_t diag_submitting_api = 0;
        uint64_t diag_player_api = 0;
        uint64_t diag_drawable_ruleset = 0;
    };

    struct full_snapshot_t {
        game_snapshot_t game;
        beatmap_data_t beatmap;
    };

}
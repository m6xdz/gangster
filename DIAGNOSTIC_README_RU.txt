LAME osu!lazer diagnostic patch

Что изменено:
- System -> system diagnostic теперь показывает Clock / Beatmap / Stack / Screen / Ruleset / API match / Play gate.
- Если состояние PLAY не определяется, Time показывает raw time, когда clock-chain всё-таки работает.
- Убран один hardcode +1120: теперь используется game_base_selected_mods из таблицы offsets.
- Сам чит намеренно НЕ получает опасный fallback "считать PLAY по одному указателю" — сначала надо увидеть, какой offset-chain реально сломан.

Как тестировать:
1. Собрать Release x64.
2. Запустить osu!lazer и LAME.
3. Открыть любую osu! карту и реально начать gameplay (не только song select).
4. Открыть LAME -> System.
5. Сделать скрин system diagnostic и прислать.

Расшифровка:
Clock FAIL -> game_base_beatmap_clock / framed_clock_final_source / framed_clock_current_time.
Beatmap FAIL -> game_base_beatmap / bindable_value.
Stack FAIL -> game_screen_stack / screen_stack_stack / List layout.
Screen FAIL -> текущий элемент stack читается неправильно.
Ruleset FAIL -> player_drawable_ruleset.
API match NO/NO -> submitting_player_api и player_api (или game_base_api).
Play gate BLOCKED -> один из обязательных сигналов выше не прошёл.

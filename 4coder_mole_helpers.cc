#include "4coder_mole_helpers.hh"

// NOTE(holger): begin
function i64
get_pos_last_non_whitespace_from_line_number(Application_Links *app, Buffer_ID buffer, i64 line_number){
    Scratch_Block scratch(app);
    Range_i64 line_range = get_line_pos_range(app, buffer, line_number);
    String_Const_u8 line = push_buffer_range(app, scratch, buffer, line_range);
    i64 result = line_range.end;
    for (i64 i = line_range.end-1; i >= line_range.start; i -= 1){
        if (!character_is_whitespace(line.str[i-line_range.start])){
            result = i;
            break;
        }
    }
    return(result);
}

function i64
get_pos_last_non_whitespace(Application_Links *app, Buffer_ID buffer, i64 pos){
    i64 line_number = get_line_number_from_pos(app, buffer, pos);
    i64 result = get_pos_last_non_whitespace_from_line_number(app, buffer, line_number);
    return(result);
}
// NOTE(holger): end


CUSTOM_COMMAND_SIG(mole_startup)
{
    fleury_startup(app);
	toggle_fullscreen(app);
}

BUFFER_HOOK_SIG(mole_file_save)
{
	default_file_save(app, buffer_id);
    clean_all_lines_buffer(app, buffer_id, CleanAllLinesMode_RemoveBlankLines);
    // no meaning for return
    return(0);
}

function void
mole_set_hooks(Application_Links *app)
{
    set_custom_hook(app, HookID_SaveFile, mole_file_save);
}

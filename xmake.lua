set_project("NumberSliderPuzzle")
set_version("0.1.0")
set_languages("c++17")

set_allowedplats("windows", "linux", "macosx")
if is_plat("windows") then
    set_toolchains("g++")
elseif is_plat("linux") then
    set_toolchains("g++")
elseif is_plat("macosx") then
    set_toolchains("clang++")
end

add_rules("mode.debug", "mode.release", "mode.test")
add_includedirs("include")

-- -------
--  tasks
-- -------

task("lint")
    on_run(function ()
        if os.host() == "windows" then
            os.execv("powershell", {"-command", string.format([[
                cd %s
                Get-ChildItem -Recurse -Include *.cpp,*.hpp | ForEach-Object {
                    clang-format -i -style=file $_.FullName
                }
            ]], os.projectdir())})
        else
            os.execv("bash", {"-cpp", string.format([[
                cd %s &&
                find . -type f \( -name '*.cpp' -o -name '*.hpp' \) -exec clang-format -i -style=file {} +
            ]], os.projectdir())})
        end
    end)
    set_menu{
        usage = "xmake lint",
        description = "Run clang-format on all .cpp and .hpp files"
    }
task_end()

@echo off
git add . 2>nul
set /p UserInputPath=Which message to commit: 2>nul
git commit -m %UserInputPath 2>nul
START /wait /B git push 2>nul
echo "Merged into master branch."

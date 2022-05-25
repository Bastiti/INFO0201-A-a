#!/bin/bash  

git add . 1>/dev/null # no stdout
echo "Which message to commit: "
read UserInputPath
git commit -m "$UserInputPath" 1>/dev/null # no stdout
git push
echo "Merged into master branch."

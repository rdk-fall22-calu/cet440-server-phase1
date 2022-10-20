build: git-pull
	gcc -std=c99 src/*.h src/*.c -o build/server

git-pull:
	git pull
#ifndef MENU_H
#define MENU_H

	class Menu{
		public:
			// Menu();
			// ~Menu();
			void executeMenu(void);
			void userInputRandomLevels(void);
			void userInputColorMode(void);

			void clearConsole(void);

			bool getRandomLevelStatus(void);
			bool getColorModeStatus(void);
			void setRandomLevelStatus(bool state);
			void setColorModeStatus(bool state);
		private:
			bool randomLevelStatus;
			bool colorModeStatus;
			int levelNumber;
	};

#endif 
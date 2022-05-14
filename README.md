# tgecho
tgecho is a small utility to log various things to telegram.

It can be used to notify you when your script finished working, for example like this:
```bash
sleep 10 && tgecho 123456 "Sleeping on $(hostname) is finished!"
```

## Installation
```bash
make
sudo make install
```

## Usage
Simply create a file with bot token in your working directory:
```bash
echo "YOUR_BOT_TOKEN" > .tgecho
```
And you are ready to use tgecho:
```bash
tgecho 123456 "Hello world!"
````

tgecho requires two arguments - `chat ID` (where to send message) and `text` of the message.
Also, tgecho requires a file named `.tgecho` to be created in your working directory. It should contain Telegram Bot API token (you can get this token from [@BotFather](https://t.me/BotFather)).

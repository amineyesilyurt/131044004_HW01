# System Programming less and more commands
Bu kod linux sistemindeki less komutunun C programı ile yazılmasını gösterir.
Programımızı ubuntuda derlemek için şu komutu kullanıyoruz :

  **gcc -c moreORless.c**
   
Daha sonra programımızı compile and link etmek için :

   **gcc moreORless.o -o moreORless**
   
Programı birkaç farklı şekilde yani farklı parametrelerle çalıştırabiliyoruz:


1. **./moreORless text.txt -l** komutuyla çalıştırırsak text.txt dosyasının içeriğini satır satır okuyabiliriz. **Enter** tuşunu kullanarak bir sonraki satıra geçilir. **u** harfine basarak bir önceki satıra geçilir. **q** harfine basarak programdan çıkılır.

![alt text](https://github.com/amineyesilyurt/MoreORLess_Command/images/moreOrless_1.png)

2. **./moreORless text.txt 20** komutuyla çalıştırıldığında text.txt'nin içeriği istenilen satır sayısı(20) kadar okunur. **ESC** tuşu ile text.txt'nin içeriği her defasında bir sonraki 20 satırı ekrana basar. Aynı şekilde **enter** tuşunu kullanarak bir sonraki satıra geçilir. **u** harfine basarak bir önceki satıra geçilir. **q** harfine basarak programdan çıkılır.

0  X  )     .  еЕ еЕ жЕ жЕ ЅмееЕ ЅФЉеЕ    Lda"юўндUїшVѓb+]
ЕC{ЎTuѓкG                                                                                                                                                                                                                                                                                                                                                                                                                                        X                (          0ц@Ѓ    щ  	  цд            џџџџџџџџpљ   џџџџ                                   џџџџџџџџџџџџ                    Ц   j       о  Х      §  `  =  c  #    <  $    р  П         f                                           џџџџ        џџ            include "stm32f10x_rtch"X                                                       џџ            CRL_CNF_SetZ                                                       џџ            CRL_CNF_ResetY                                                       џџ            RTC_LSB_MaskY                                                      џџ            RTC_MSB_MaskZ                                                      џџ            PRLH_MSB_MaskY      1       ?         1                 `Ќ           џџ          RTC_ITConfig`      H       L         H                  РІ           џџ           RTC_EnterConfigMode_   	   U       Y         U                   ­           џџ           RTC_ExitConfigMode[   
   b       h         b                  @Љ           џџ           RTC_GetCounter[      q       {         q                 рЎ           џџ           RTC_SetCounter]                   	                     `Ї
           џџ           RTC_GetPrescaler]             Ђ                          Ѕ           џџ   
        RTC_SetPrescalerY      Ћ       Е         Ћ                  Ј           џџ           RTC_SetAlarm[      О       Ц      	   О                   Ј           џџ           RTC_GetDivider`      а       ж         а                  @Ў           џџ          RTC_WaitForLastTask_      т       ы      
   т                  v           џџ          RTC_WaitForSynchro^      њ       
        њ                 Иv           џџ          RTC_GetFlagStatusZ                                     xu           џџ           RTC_ClearFlag\      -      ?        -  	              иy           џџ          RTC_GetITStatusb      L      S        L                Иl
           џџ           RTC_ClearITPendingBit   
          @чh?    П    Pх№    рЄ         pљ    џџџџ                                     џџџџџџџџџџџџ                    j    Ќ   U       Q      1       1           1       4              џџџџ        џџ            voidS      1      1         1                 Њ            џџ            RTC_ITU      1   .   1   6      1   .               І            џџ            NewStatea      7      :         7                РЋ            џџ            if NewState!=DISABLEQ      ;      >         ;                @Є            џџ            else   
          `цИ=    T   d   ахHz   `Ќ         pљ    џџџџ                                     џџџџџџџџџџџџ                        P      1      1          1      4              џџџџ        џџ            u16   
          ацx;    `   d    цИz   `Ќ         pљ    џџџџ                                     џџџџџџџџџџџџ                        \      1   .   1   .       1   .   4              џџџџ        џџ            FunctionalState    
           ци>        d   pцјz   `Ќ         pљџџџџџџџџ                                      џџџџџџџџџџџџ                        
          ц?        d   Ац(z   `Ќ          pљџџџџџџџџ                                      џџџџџџџџџџџџ                       
          Рцј?    U   d   №цHz   рЄ         pљ    џџџџ                                     џџџџџџџџџџџџ                        Q      H       H           H       4              џџџџ        џџ            void   
           чШ?    U   d   АшИz   рЄ	         pљ    џџџџ                                     џџџџџџџџџџџџ                        Q      U       U           U       4              џџџџ        џџ            void   
           ш<    Ј   ќ   №ъ№KЊ   рЄ
         pљ    џџџџ                                     џџџџџџџџџџџџ                    T       P      b       b           b       4              џџџџ        џџ            u32P      d      d         d                                џџ            tmp   
           ъ(@    В     №щЂ   рЄ         pљ    џџџџ                                     џџџџџџџџџџџџ                    U       Q      q       q           q       4              џџџџ        џџ            voidY      q      q   $      q                 рЉ            џџ            CounterValue   
          `щ;    T   d   ръ(z   рЎ          pљ    џџџџ                                     џџџџџџџџџџџџ                        P      q      q          q      4              џџџџ        џџ            u32   
          Ры@    Ј   ќ   аы NЊ   рЄ         pљ    џџџџ                                     џџџџџџџџџџџџ                    T       P                               4              џџџџ        џџ            u32P                                                     џџ            tmp   
          @яИ@    Д     РюРЂ   рЄ         pљ    џџџџ                                     џџџџџџџџџџџџ                    U       Q                               4              џџџџ        џџ            void[               (                        Ћ            џџ            PrescalerValue   
          рюш:    T   d    яz   Ѕ          pљ    џџџџ                                     џџџџџџџџџџџџ                        P                            4              џџџџ        џџ            u32   
          аюH;    А     рэЂ   рЄ         pљ    џџџџ                                     џџџџџџџџџџџџ                    U       Q      Ћ       Ћ           Ћ       4              џџџџ        џџ            voidW      Ћ      Ћ          Ћ                  ­            џџ
            
AlarmValue   
          №юЈ;    T   d   №эшz    Ј          pљ    џџџџ                                     џџџџџџџџџџџџ                        P      Ћ      Ћ          Ћ      4              џџџџ        џџ            u32   
          яи;    Ј   ќ   @ю RЊ   рЄ   	      pљ    џџџџ                                     џџџџџџџџџџџџ                    T       P      О       О           О       4              џџџџ        џџ            u32P      Р      Р         Р                                џџ            tmp   
           ю?    Ф   &  юЈ$Ј   рЄ         pљ   џџџџ                                     џџџџџџџџџџџџ                        U   Q      а       а           а       4              џџџџ        џџ            voidk      г      е         г                иo            џџ            while (RTC->CRL&RTC_FLAG_RT    
           яx>        d   0ю8z   @Ў         pљџџџџџџџџ                                      џџџџџџџџџџџџ                       
          Pю<    Ф   &  ю0-Ј   рЄ         pљ   џџџџ                                     џџџџџџџџџџџџ                        U   Q      т       т           т       4              џџџџ        џџ            voidk      ш      ъ         ш                иt            џџ            while (RTC->CRL&RTC_FLAG_RS    
          э8<        d    юz   v         pљџџџџџџџџ                                      џџџџџџџџџџџџ                       
          `юh<    Я  7  pю х   рЄ   
      pљ   џџџџ                                     џџџџџџџџџџџџ                    Д   z        [   W      њ       њ           њ       4              џџџџ        џџ
            
FlagStatusU      њ   !   њ   )      њ   !              Xm            џџ            RTC_FLAGV      ќ      ќ         ќ                               џџ	            	bitstatush                                  l            џџ            if (RTC->CRL&RTC_FLAG)!=Q                                  xz           џџ            else   
          эШ<    T   d   юЈz   Иv         pљ    џџџџ                                     џџџџџџџџџџџџ                        P      њ   !   њ   !       њ   !   4              џџџџ        џџ            u16    
           эј<        d   Аэ8z   Иv         pљџџџџџџџџ                                      џџџџџџџџџџџџ                        
          @ё8?        d    ёЈz   Иv         pљџџџџџџџџ                                      џџџџџџџџџџџџ                       
          p№(=    Ў     Р№ЈЂ   рЄ         pљ    џџџџ                                     џџџџџџџџџџџџ                    U       Q                            4              џџџџ        џџ            voidU                                   јm            џџ            RTC_FLAG   
          `№=    T   d   0ёz   xu          pљ    џџџџ                                     џџџџџџџџџџџџ                        P                         4              џџџџ        џџ            u16   
          №X=    Ы  А   №и^Њ   рЄ         pљ   џџџџ                                     џџџџџџџџџџџџ                    А   v  
      Y   U      -      -          -      4              џџџџ        џџ            ITStatusS      -     -  #      -                8y            џџ            RTC_ITV      /     /        /                              џџ	            	bitstatush      6     9        6               Иq            џџ            if ((RTC->CRH&RTC_IT)!=(Q      :     =        :               {           џџ            else   
           ёЈ>    T   d   @№z   иy         pљ    џџџџ                                     џџџџџџџџџџџџ                        P      -     -         -     4              џџџџ        џџ            u16    
          Pяш=        d   pяhz   иy         pљџџџџџџџџ                                      џџџџџџџџџџџџ                        
          №>        d   аяz   иy         pљџџџџџџџџ                                      џџџџџџџџџџџџ                       
          а№H>    Ќ     Ряи>Ў   рЄ         pљ    џџџџ                                     џџџџџџџџџџџџ                    U       Q      L      L          L      4              џџџџ        џџ            voidS      L     L  %      L                n            џџ            RTC_IT   
          А№hB    T   d   0№xz   Иl          pљ    џџџџ                                     џџџџџџџџџџџџ                        P      L     L         L     4              џџџџ        џџ            u16$                             V  V         0чXuЉ                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        pхxd             (         Pц@r          !          L      T          H       M           U       Z           b       i           О       Ч           њ                       	                        -      @          :      >         6      :                           1       @           ;       ?          7       ;          Ћ       Ж           q       |                  Ѓ           а       з           г       ж          т       ь           ш       ы          
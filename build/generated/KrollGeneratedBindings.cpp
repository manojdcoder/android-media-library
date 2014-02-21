/* C++ code produced by gperf version 3.0.3 */
/* Command-line: gperf -L C++ -E -t /private/var/folders/dz/11lc735d1vbc55kgztnn28r40000gn/T/Aditi/media-generated/KrollGeneratedBindings.gperf  */
/* Computed positions: -k'' */

#line 3 "/private/var/folders/dz/11lc735d1vbc55kgztnn28r40000gn/T/Aditi/media-generated/KrollGeneratedBindings.gperf"


#include <string.h>
#include <v8.h>
#include <KrollBindings.h>

#include "com.mykingdom.media.ExampleProxy.h"
#include "com.mykingdom.media.MediaModule.h"


#line 14 "/private/var/folders/dz/11lc735d1vbc55kgztnn28r40000gn/T/Aditi/media-generated/KrollGeneratedBindings.gperf"
struct titanium::bindings::BindEntry;
/* maximum key range = 2, duplicates = 0 */

class MediaBindings
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static struct titanium::bindings::BindEntry *lookupGeneratedInit (const char *str, unsigned int len);
};

inline /*ARGSUSED*/
unsigned int
MediaBindings::hash (register const char *str, register unsigned int len)
{
  return len;
}

struct titanium::bindings::BindEntry *
MediaBindings::lookupGeneratedInit (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 2,
      MIN_WORD_LENGTH = 31,
      MAX_WORD_LENGTH = 32,
      MIN_HASH_VALUE = 31,
      MAX_HASH_VALUE = 32
    };

  static struct titanium::bindings::BindEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 17 "/private/var/folders/dz/11lc735d1vbc55kgztnn28r40000gn/T/Aditi/media-generated/KrollGeneratedBindings.gperf"
      {"com.mykingdom.media.MediaModule", ::com::mykingdom::media::MediaModule::bindProxy, ::com::mykingdom::media::MediaModule::dispose},
#line 16 "/private/var/folders/dz/11lc735d1vbc55kgztnn28r40000gn/T/Aditi/media-generated/KrollGeneratedBindings.gperf"
      {"com.mykingdom.media.ExampleProxy", ::com::mykingdom::media::media::ExampleProxy::bindProxy, ::com::mykingdom::media::media::ExampleProxy::dispose}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 18 "/private/var/folders/dz/11lc735d1vbc55kgztnn28r40000gn/T/Aditi/media-generated/KrollGeneratedBindings.gperf"


// DO NOT EDIT THIS FILE.  IT IS AUTOMATICALLY GENERATED.
// longbow-generate-about 1.0.20160118.99a4a1be 2016-01-19T04:29:09Z

#ifndef librta_About_h
#define librta_About_h
/**
 * Embedded string containing information for the what(1) command.
 *
 */
extern const char *librta_What;

/**
 * Return the name as a C string.
 *
 * @return The name as a C string.
 */
const char *librtaAbout_Name(void);

/**
 * Return the version as a C string.
 *
 * @return The version as a C string.
 */
const char *librtaAbout_Version(void);

/**
 * Return the About text as a C string.
 *
 * @return The About text as a C string.
 */
const char *librtaAbout_About(void);

/**
 * Return the minimum copyright notice as a C string.
 *
 * @return The minimum copyright notice as a C string.
 */
const char *librtaAbout_MiniNotice(void);

/**
 * Return the short copyright notice as a C string.
 *
 * @return The short copyright notice as a C string.
 */
const char *librtaAbout_ShortNotice(void);

/**
 * Return the long copyright notice as a C string.
 *
 * @return The long copyright notice as a C string.
 */
const char *librtaAbout_LongNotice(void);

#endif // librta_About_h

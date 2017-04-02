<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPTiff;

use PHPExiftool\Driver\AbstractTag;

class DateTime extends AbstractTag
{

    protected $Id = 'DateTime';

    protected $Name = 'DateTime';

    protected $FullName = 'XMP::tiff';

    protected $GroupName = 'XMP-tiff';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-tiff';

    protected $g2 = 'Image';

    protected $Type = 'date';

    protected $Writable = true;

    protected $Description = 'Date/Time Modified';

    protected $local_g2 = 'Time';

}

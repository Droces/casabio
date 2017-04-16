<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\SubIFD;

use PHPExiftool\Driver\AbstractTag;

class JpgFromRawLength extends AbstractTag
{

    protected $Id = 514;

    protected $Name = 'JpgFromRawLength';

    protected $FullName = 'Exif::Main';

    protected $GroupName = 'SubIFD';

    protected $g0 = 'EXIF';

    protected $g1 = 'IFD0';

    protected $g2 = 'Image';

    protected $Type = 'int32u';

    protected $Writable = true;

    protected $Description = 'Jpg From Raw Length';

    protected $local_g1 = 'SubIFD';

    protected $flag_Protected = true;

    protected $Index = 5;

}